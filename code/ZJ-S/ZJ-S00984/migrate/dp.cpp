#include <bits/stdc++.h>
using namespace std;

int main() {
    int tot=0;
    while(true) {
        system("./data");
        cerr<<++tot<<endl;
        system("./my");
        system("./bf");
        if(system("diff my.out bf.out")) {
            puts("WA");
            return 0;
        }
    }
    return 0;
}
