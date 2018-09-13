# Tina_R16

## 1.配置环境
`cd ~/Tina_R16`

`source build/envsetup.sh`
## 2.加载板子配置
`lunch astar_parrot-tina`
## 3.编译
`make -j1`
## 4.打包
`pack -d`

# 添加交叉编译环境
`export PATH=$PATH:~/Tina_R16/lichee/brandy/gcc-linaro/bin`
# 编译openssl
`cd ~/Tina_R16/lichee/brandy/extern-libs`

`tar -xvf openssl-secure-system.tar.bz2`

`cd openssl-1.0.1g-for-secure-system/openssl-1.0.1g`

编辑Makefile,修改276行、277行修改为

`cp -v libssl.a ~/Tina_R16/lichee/brandy/gcc-linaro/lib/gcc/arm-linux-gnueabi/4.6.3/libssl.a`

`cp -v libcrypto.a ~/Tina_R16/lichee/brandy/gcc-linaro/lib/gcc/arm-linux-gnueabi/4.6.3/libcrypto.a`

# 编译u-boot
## 1.进入u-boot目录
`cd ~/Tina_R16/lichee/brandy/u-boot-2011.09`
## 2.加载配置文件
`make sun8iw5p1_config`
## 3.编译
`make -j1`

>编译会提醒找不到 -lssl 和-lcrypto，问题在交叉编译器缺少动态连接库ssl.so和crypto.so，说明openssl未编译。



