# 1. Base system
FROM ubuntu:22.04

# 2. Avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# 3. Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

# 4. Install FTXUI
RUN git clone https://github.com/ArthurSonzogni/FTXUI.git /ftxui \
    && cd /ftxui \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make -j4 \
    && make install

# 5. Set working directory
WORKDIR /app

# 6. Copy your project into container
COPY . .

# 7. Build your project (fresh build folder)
RUN mkdir build && cd build && cmake .. && make -j4

# 8. Default command to run your app
CMD ["./build/ftxui_app"]
