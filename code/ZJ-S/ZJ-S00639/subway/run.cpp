#include <bits/stdc++.h>
using namespace std;

int main(){
    system("g++ -o subway -O2 subway.cpp -std=c++17");
    int T=7;
    for(int i=1;i<=T;i++){
        cerr<<"Runing on Test#"<<i<<"\n";
        char c[100];
        string s="subway"+to_string(i);
        string t;
        system("del subway.in");
        t="copy "+s+".in subway.in";
        auto tochr=[&]()->void {
            memset(c,0,sizeof(c));
            for(int i=0;t[i];i++)c[i]=t[i];
        };
        tochr(),system(c);
        double be=clock()/1000.0;
        system("subway.exe");
        double ed=clock()/1000.0;
        cerr<<"time:"<<ed-be<<'\n';
        t="fc /w "+s+".ans subway.out";
        tochr();
        if(system(c))break;
        cerr<<"Correct\n";
    }
    return 0;
}