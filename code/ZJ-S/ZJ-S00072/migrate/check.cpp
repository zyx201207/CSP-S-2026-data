#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e5+5;

void _main(){
    if(system("g++ migrate.cpp -o migrate -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra"))return;
    if(system("g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra"))return;
    if(system("g++ gen.cpp -o gen -std=c++14 -DLOCAL -O2 -Wall -Wextra"))return;
    for(int i=1;;i++){
        printf("Case %d\n",i);
        if(system("./gen>in"))break;
        if(system("./migrate<in>out"))break;
        if(system("./std<in>ans"))break;
        if(system("diff -Z out ans"))break;
    }
}
signed main(){
    clock_t _st=clock();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ code.cpp -o code -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ code.cpp -o code -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ code.cpp -o code -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ code.cpp -o code -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/