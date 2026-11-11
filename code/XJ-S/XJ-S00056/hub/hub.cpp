int main(){}
/*
import os
from subprocess import run
pname=input("name>>")
while True:
    input("...")
    print("compile...")
    run(f"g++ {pname}.cpp -O2 -std=c++14 -static -o a",shell=True)
    print("test:")
    i=1
    while True:
        if not os.path.exists(f"{pname}{i}.in"):
            break
        print(f"----test-{i}---")
        run(f"cp {pname}{i}.in {pname}.in",shell=True)
        run(f"./a",shell=True)
        res=run(f"diff -u {pname}.out {pname}{i}.ans",shell=True)
        if res.returncode:
            break
        i+=1
*/