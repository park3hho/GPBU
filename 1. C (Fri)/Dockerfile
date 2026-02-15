FROM gcc:13

# PostgreSQL C 라이브러리 설치
RUN apt-get update && apt-get install -y libpq-dev

WORKDIR /workspace

# main.c를 컨테이너 안으로 복사
COPY . .

# 컴파일
RUN gcc Assignment/main.c -I/usr/include/postgresql -lpq -o Assignment/app


# 실행
CMD ["./app"]
