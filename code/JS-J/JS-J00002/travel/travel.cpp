#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int jud1(){
    for(int i=0;i<2;i++){
        if(a[i]!=c[i]){
            return 0;
        }
    }
    return 1;
}
int jud2(){
    if(!jud1())return 0;
    for(int i=0;i<2;i++){
        if(b[i]!=d[i]){
            return 0;
        }
    }
    return 1;
}
int jud3(){
    if(!jud1()||!jud2())return 0;
    int x,y;
    if(b[2]=='A')x=1;
    if(b[2]=='B')x=1;
    if(b[2]=='C')x=1;
    if(b[2]=='D')x=2;
    if(b[2]=='F')x=2;
    if(d[2]=='A')y=1;
    if(d[2]=='B')y=1;
    if(d[2]=='C')y=1;
    if(d[2]=='D')y=2;
    if(d[2]=='F')y=2;
    if(x==y)return 1;
    return 0;
}
int jud4(){
    if(!jud1()||!jud2()||!jud3())return 0;
    int x,y;
    if(b[2]=='A')x=1;
    if(b[2]=='B')x=2;
    if(b[2]=='C')x=3;
    if(b[2]=='D')x=5;
    if(b[2]=='F')x=6;
    if(d[2]=='A')y=1;
    if(d[2]=='B')y=2;
    if(d[2]=='C')y=3;
    if(d[2]=='D')y=5;
    if(d[2]=='F')y=6;
    if(x-y==1||x-y==-1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    cout<<jud1()<<jud2()<<jud3()<<jud4();
    return 0;
}
