cmd_/home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax/.install := bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/uapi/linux/wimax i2400m.h; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/linux/wimax ; bash scripts/headers_install.sh /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax /home/wangyaliang/workspace/tina/lichee/linux-3.10/include/generated/uapi/linux/wimax ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax/$$F; done; touch /home/wangyaliang/workspace/tina/out/tulip-d1/compile_dir/toolchain/linux-dev//include/linux/wimax/.install