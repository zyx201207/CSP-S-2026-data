#include <bits/stdc++.h>
#define N 200100
using namespace std;
string s[N];
bool flag[N];
int read(){
    int x=0;
    char c=getchar_unlocked();
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        int f=read();
        string t="";
        while(f){
            if(f&1)
                t+='1';
            else
                t+='0';
            f>>=1;
        }
        while(t.length()!=31){
            t+='0';
        }
        for(int j=30;j>=0;j--){
            s[i]+=t[j];
        }
    }
    for(int j=0;j<=30;j++){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(!flag[i])
                sum+=(s[i][j]-'0');
        }
        if(sum>=m){
            ans+=(1<<(30-j));
            for(int i=1;i<=n;i++){
                if(s[i][j]=='0'){
                    flag[i]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
