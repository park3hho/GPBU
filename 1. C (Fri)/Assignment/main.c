#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

// DB 연결
PGconn* connectDB() {
    PGconn *conn = PQconnectdb(
        "host=db user=user password=1234 dbname=score"
    );

    if (PQstatus(conn) != CONNECTION_OK) {
        printf("DB 연결 실패: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        exit(1);
    }
    return conn;
}

// 1️⃣ 성적 처리 (If~Else)
char* getGrade(int score) {
    switch(score / 10) {
        case 10:
        case 9:
            return "A";
        case 8:
            return "B";
        case 7:
            return "C";
        case 6:
            return "D";
        default:
            return "F";
    }
}

// 2️⃣ 성적 입력
void insertStudent(PGconn *conn) {
    char name[50];
    int score;
    char *grade;

    printf("이름 입력: ");
    scanf("%s", name);
    printf("성적 입력: ");
    scanf("%d", &score);

    grade = getGrade(score);

    char query[256];
    sprintf(query,
        "INSERT INTO student (name, score, grade) "
        "VALUES ('%s', %d, '%s');",
        name, score, grade);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) == PGRES_COMMAND_OK)
        printf("입력 성공! 등급: %s\n", grade);
    else
        printf("입력 실패\n");

    PQclear(res);
}

// 3️⃣ 검색 기능
void searchStudent(PGconn *conn) {
    char name[50];

    printf("검색할 이름: ");
    scanf("%s", name);

    char query[256];
    sprintf(query,
        "SELECT name, score, grade FROM student "
        "WHERE name='%s';", name);

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("검색 실패\n");
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);

    for (int i = 0; i < rows; i++) {
        printf("이름: %s\n", PQgetvalue(res, i, 0));
        printf("성적: %s\n", PQgetvalue(res, i, 1));
        printf("등급: %s\n", PQgetvalue(res, i, 2));
        printf("------------\n");
    }

    PQclear(res);
}


// 4️⃣ 전체 학생 조회
void viewAllStudents(PGconn *conn) {
    char query[] = "SELECT name, score, grade FROM student;";

    PGresult *res = PQexec(conn, query);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("전체 조회 실패\n");
        PQclear(res);
        return;
    }

    int rows = PQntuples(res);

    if (rows == 0) {
        printf("등록된 학생이 없습니다.\n");
        PQclear(res);
        return;
    }

    printf("\n===== 전체 학생 목록 =====\n");

    for (int i = 0; i < rows; i++) {
        printf("이름: %s\n", PQgetvalue(res, i, 0));
        printf("성적: %s\n", PQgetvalue(res, i, 1));
        printf("등급: %s\n", PQgetvalue(res, i, 2));
        printf("------------------------\n");
    }

    PQclear(res);
}

int main() {
    PGconn *conn = connectDB();
    int choice;

    while (1) {
        printf("\n1. 성적 입력\n2. 성적 검색\n3. 전체 조회\n4. 종료\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertStudent(conn);
                break;
            case 2:
                searchStudent(conn);
                break;
            case 3:
                viewAllStudents(conn);
                break;
            case 4:
                PQfinish(conn);
                exit(0);
            default:
                printf("잘못된 입력\n");
        }
    }
}
