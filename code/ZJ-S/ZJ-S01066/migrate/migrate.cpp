#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const ll inf=2e18;
const ll mod=1e9+33;
ll a[N];
ll tid;
ll fr[N];
ll is[N];
ll f[N],g[N];
ll n,d;
ll ans=0;
ll cnt[N];
void bfn2(){
//    printf("haha");
    ans=0;
    deque<int> q;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            cnt[j]=0;
            f[j]=1e9;
            g[j]=0;
        }
        f[i]=0;
        g[i]=1;
        cnt[0]=1;
        while(!q.empty()) q.pop_back();
        q.push_back(i);
        for(int j=i+1;j<=n;j++){
            while(!q.empty() && (a[j]-a[q.front()])>d){
                cnt[f[q.front()]]=(cnt[f[q.front()]]-g[q.front()]+mod)%mod;
                q.pop_front();
            }
            if(q.empty()) break;
            f[j]=f[q.front()]+1;
            g[j]=cnt[f[q.front() ]];
//            g[j]=g[j]%mod;

            cnt[f[j]]=cnt[f[j]]+g[j];
            if(cnt[f[j]]>=mod) cnt[f[j]]-=mod;
            if(g[j]==2) ans++;
            q.push_back(j);
//            printf("j=%d \n",j);
        }
    }
//    for(int j=1;j<=n;j++){
//        printf("%lld %lld\n",f[j],g[j]);
//    }
    printf("%lld\n",ans);
}
void bfn3(){
    ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            g[j]=0;
            f[j]=1e9;
        }
        f[i]=0;
        g[i]=1;
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if((a[k]-a[j])>d) break;
                if(f[k]==(f[j]+1)){
                    g[k]+=g[j];
                }else if(f[k]>(f[j]+1)){
                    g[k]=g[j];
                    f[k]=f[j]+1;
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(g[j]==2){
                ans++;
//                printf("%d %d\n",i,j);
            }

        }
    }
    printf("%lld\n",ans);
}
ll b[N];
ll lst1[N],lst2[N];
void ck(ll len){
    for(int i=0;i<=len+1;i++){
        is[i]=0;
        lst1[i]=0;
        lst2[i]=0;
    }
    for(int i=1;i<=len-3;i++){
        if((a[i+2]-a[i])<=d && (a[i+3]-a[i+1])<=d && (a[i+3]-a[i])>d){
            is[i]=1;
        }
    }
    ll lp=len;
    for(int i=len;i>=1;i--){
        if(is[i]){
            lst1[i]=i+3;
            lst2[i]=lp;
            lp=i+2;
        }else{
            lst1[i]=lst1[i+1];
            lst2[i]=lst2[i+1];
        }
    }
    for(int i=1;i<=len;i++){
        if(lst1[i]<=lst2[i]){
            if(lst1[i]!=0)
                ans+=lst2[i]-lst1[i]+1;
        }
    }
}
void xza(){
    ans=0;
    if(n<4){
        printf("%lld\n",ans);
        return;
    }
    if((a[4]-a[1])>d && (a[4]-a[2])<=d){
        ans=n-3;
        printf("%lld\n",ans);
        return;
    }
    int r=4;
    for(int i=4;i<=n;i++){
        if((a[i]-a[1])>d) break;
        if((a[i+1]-a[1])<=d) continue;
        while((a[r]-a[i-2])<=d) r++;
        if((a[r]-a[i-1])<=d){
            ans=n-r+1;
            break;
        }
    }
    printf("%lld\n",ans);
}
void work(){

    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    ans=0;
    if(tid<=10 && tid!=0){
        bfn2();
        return ;
    }
    if(tid==11 || tid==12 || tid==0){
        xza();
        return;
    }
}
int main(){
//    system("diff -w migrate.out migrate4.ans");
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll T;
    scanf("%lld%lld",&tid,&T);
    for(;T;T--) work();
    return 0;
}
