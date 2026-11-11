#include<bits/stdc++.h>
#define int long long
#define r(x) x=read()
#define w(x) write(x)
#define sp putchar(' ')
#define en putchar('\n')
using namespace std;
int read(){int x=0,f=1;char ch=getchar();while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x*f;}
void write(int x){if(x<0) x=-x,putchar('-');if(x>9) write(x/10);putchar(x%10^48);}
const int N=5e5+10;
const int M=3e5+10;
int a[N];
vector<bool>dp[N];
int n,m;
int last[M];
int out[N];
vector<bool> tmp;
int cnt[M];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    r(n),r(m);
    for(int i=0;i<=m;i++) tmp.push_back(0);
    for(int i=1;i<=n;i++){
        r(a[i]);
        if(last[a[i]]) out[last[a[i]]]=i;
        last[a[i]]=i;
        dp[i]=tmp;
    }
    dp[n+1]=tmp;
    for(int i=n;i>=1;i--){
        if(out[i]) dp[i]=dp[out[i]];
        else dp[i]=dp[i+1];
        dp[i][a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[j]+=dp[i][j];
        }
    }
    for(int i=1;i<=m;i++) w(cnt[i]),sp;
    return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
