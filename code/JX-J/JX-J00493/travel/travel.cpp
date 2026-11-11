#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a,b;
string c,d;
bool ans,ans2,ans3,ans4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        ans=true;
        if(c[0]==d[0]&&c[1]==d[1]){
            ans2=true;
            if(c[2]=='A'&&(d[2]=='B'||d[2]=='C')||c[2]=='B'&&(d[2]=='A'||d[2]=='C')||c[2]=='C'&&(d[2]=='A'||d[2]=='B')||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D') ans3=true;
            if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&(d[2]=='A'||d[2]=='C')||c[2]=='C'&&d[2]=='B'||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D') ans4=true;
        }
    }
    cout<<ans<<ans2<<ans3<<ans4;
    return 0;
}
