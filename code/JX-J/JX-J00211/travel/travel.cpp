#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool w,x,y,z;
int f(string s){
    int res=0;
    int len=s.size();
    for(int i=0;i<len-1;i++){
        res=res*10+(int)(s[i]-48);
    }
    return res;
}
bool check(char a,char b){
    if(b<a) swap(a,b);
    if(a=='A' && b=='B') return 1;
    if(a=='A' && b=='C') return 1;
    if(a=='B' && b=='C') return 1;
    if(a=='D' && b=='F') return 1;
    return 0;
}
bool check1(char a,char b){
    if(b<a) swap(a,b);
    if(a=='A' && b=='B') return 1;
    if(a=='B' && b=='C') return 1;
    if(a=='D' && b=='F') return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int num1=f(b);
    int num2=f(d);
    if(a==c){
        w=1;
        if(num1==num2){
            x=1;
            if(check(b[2],d[2])){
                y=1;
                if(check1(b[2],d[2])){
                    z=1;
                }
            }
        }
    }
    cout<<w<<x<<y<<z;
    return 0;
}
