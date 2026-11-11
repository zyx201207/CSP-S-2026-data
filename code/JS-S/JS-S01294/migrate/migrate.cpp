#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,c,t,m;
struct node{
    int num,cnt;
};
node dp[5010][5010];
int a[2000010];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void sol2(){
    int d=a[2]-a[1];
    if(m<d*2) cout<<0<<endl;
    else{
        int t=m/d;
        cout<<max(n+1-t*2,0ll)<<endl;
    }
}
void sol1(){
    int ans=0;
    for(int i=1; i<=n; i++) dp[i][i+1].num=1,dp[i][i+1].cnt=1;
    for(int i=1; i<=n; i++){
        int pos=a[i],tt=i+1,c=0;
        while(tt<=n){
            pos+=m,c++;
            bool f=0;
            while(pos>=a[tt]&&tt<=n){
                dp[i][tt].cnt=c;
                ++tt;
                f=1;
            }
            if(f) pos=a[tt-1];
        }
    }
    for(int len=2; len<=n; len++){
        for(int l=1; l<=n-len+1; l++){
            int r=l+len-1;
            for(int k=l+1; k<=r-1; k++){
                if(dp[l][k].cnt+dp[k][r].cnt==dp[l][r].cnt) dp[l][r].num+=dp[l][k].num*dp[k][r].num;
            }
        }
    }
    for(int l=1; l<=n-1; l++){
        for(int r=l+1; r<=n; r++){
            if(dp[l][r].num==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),m=read();
        for(int i=1; i<=n; i++) a[i]=read();
        if(c==12||c==11) sol2();
        else sol1();
    }
    return 0;
}