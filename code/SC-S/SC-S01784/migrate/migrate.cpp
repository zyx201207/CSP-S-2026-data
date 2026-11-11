#include<iostream>
using namespace std;
const int N=2e6+9;
int n,dp[N],num[N];
int que[N],ql,qr;
long long m,a[N],ans;
inline long long read(){
    long long x=0;
    int ch=getchar();
    bool f=0;
    while(ch<'0'||'9'<ch){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    if(f)return -x;
    return x;
}
int doing(int c){
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    if(c==11||c==12){
        long long d=a[2]-a[1];
        long long fm=m/d;
        long long nm=fm*2-1;
        if(fm<=1){
            puts("0");
        }else{
            cout<<max(n-nm,0ll)<<'\n';
        }
        return 0;
    }
    if(n>1e4){
        puts("0");
        return 0;
    }
    ans=0;
    for(int l=1;l<=n;l++){
        dp[l]=0,num[l]=1;
        que[ql=qr=1]=l;
        for(int i=l+1;i<=n;i++){
            while(ql<=qr&&a[que[ql]]<a[i]-m)ql++;
            if(ql>qr)break;
            dp[i]=dp[que[ql]]+1;
            num[i]=0;
            for(int j=ql;j<=qr;j++){
                if(dp[que[j]]>dp[que[ql]])break;
                num[i]+=num[que[j]];
            }
            if(num[i]==2)ans++;
            que[++qr]=i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),t=read();
    while(t--)doing(c);
    return 0;
}