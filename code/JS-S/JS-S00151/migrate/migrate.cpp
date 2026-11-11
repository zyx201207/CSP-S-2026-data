#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int read(){
    int x=0,f=1;char p=getchar();
    while(!isdigit(p)){if(p=='-')f=-1;p=getchar();}
    while(isdigit(p))x=x*10+p-'0',p=getchar();
    return x*f;
}
inline void write(ll x){
    if(x){char buf[20],pi=0;
        while(x)buf[++pi]='0'+x%10,x/=10;
        while(pi)putchar(buf[pi--]);
    }else putchar('0');
    putchar('\n');
}
int T,n;ll x[N],d,m;
int p,l[N],r[N],cl[N],cr[N];
inline bool check(int t){return t>1&&t<n&&r[t-1]==t+1&&l[t+1]==t-1;}
ll ans;int cnt[2];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read();T=read();
    for(;T--;){
        n=read(),d=read();
        for(int i=1;i<=n;i++)x[i]=read(),cl[i]=cr[i]=0;
        p=1;
        for(int i=1;i<=n;i++){
            while(x[i]-x[p]>d)p++;
            l[i]=p;
            if(p!=i)cr[p]++;
        }
        p=n;
        for(int i=n;i>=1;i--){
            while(x[p]-x[i]>d)p--;
            r[i]=p;
            if(p!=i)cl[p]++;
        }
        ans=0;
        for(int i=1;i<n;i++)ans+=1LL*cr[i]*cl[i+1]-(l[i]==i-1&&r[i-1]==i);
        for(int i=1;i<=n;i++)cl[i]=cr[i]=1;
        for(int i=1;i<=n;i++)if(l[r[i]]==i)cl[r[i]]+=cl[i];
        for(int i=n;i>=1;i--)if(r[l[i]]==i)cr[l[i]]+=cr[i];
        cnt[0]=cnt[1]=0;
        for(int i=1,o=1;i<=n;i++,o^=1){
            if(check(i)){
                ans+=1LL*cnt[o^1]*(r[i]-i);
                cnt[o]+=i-l[i];
            }else cnt[0]=cnt[1]=0;
        }
        write(ans);
    }
    return 0;
}