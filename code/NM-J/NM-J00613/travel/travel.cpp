#include<bits/stdc++.h>
using namespace std;
string rn,xn,rs,xs;
int a=0,b=0,c=0,d=0;
bool check(string x,string y){
    char xx=x[2],yy=y[2];
    if(xx>='A'&&xx<='C'&&yy>='A'&&yy<='C') return true;
    if(xx=='D'&&yy=='F'||yy=='D'&&xx=='F') return true;
    return false;
}
bool dd(string x,string y){
    char xx=x[2],yy=y[2];
    if(xx=='D'&&yy=='F'||yy=='D'&&xx=='F') return true;
    int k=abs(xx-yy);
    if(k==1) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rn>>rs>>xn>>xs;
    if(rn==xn) a=1;
    if(a==1&&rs[0]==xs[0]&&rs[1]==xs[1]) b=1;
    if(a==1&&b==1&&check(rs,xs)) c=1;
    if(a==1&&b==1&&c==1&&dd(rs,xs)) d=1;
    cout<<a<<b<<c<<d<<endl;
    return 0;
}
