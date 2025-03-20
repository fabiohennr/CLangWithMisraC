FROM ubuntu:latest

COPY . /code_example

RUN apt-get update && apt-get install -y \
    build-essential \
    nano \
    tmux \
    clang \
    clang-tools \
    clang-tidy

WORKDIR /code_example

CMD ["/bin/bash", "-c", "tmux attach || tmux new-session"]