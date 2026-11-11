#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int dp[N];
inline int read(){
    int x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0'||ch>'9'){
        if(ch==EOF) return 0;
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar_unlocked();
        if(ch==EOF) break;
    }
    return x*f;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    dp[0]=(1<<30)-1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j]=max(dp[j], dp[j-1] & a[i]);
        }
    }
    printf("%d\n%d",dp[m],dp[1]);
    return 0;
}
