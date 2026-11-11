//author:lklklklklkl
//Why are you still here,an old Senior 3 WHKer?
//你是圣诞老人送给我，好孩子的礼物
//Encode:UTF-8
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
typedef long long ll;
int x[2000005],nxt0[2000005],nxt[2000005],prv[2000005],power[2000005],lg2[2000005];
bool ed[2000005];
ll ans;
void solveA(){
    int delta=d/(x[2]-x[1]),beta=2*delta-1;
    if(delta>=n-1||delta==0||delta==1){
        printf("0\n");
        return;
    }
    printf("%lld\n",n-beta);
}
void solveB(){
    int l=n+1,r=0;
    for(int i=1;i<=n;i++)
        if(prv[i]==1&&nxt[i]==n)
            l=min(l,i),r=i;
    if(r-l>1){
        printf("0\n");
        return;
    }
    if(r-l==1){
        int ans=0;
        printf("%lld\n",(l-1)*(n-(nxt[l-1])));
        return;
    }
    if(r==l){
        if(r==1||r==2){
            printf("0\n");
            return;
        }
        printf("%lld\n",(l-2)*(nxt[l-2]-nxt[l-1]));
        return;
    }
}
void solve(){
    memset(ed,0,sizeof(ed));
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    ans=0;
    for(int i=1;i<=n;i++){
        nxt[i]=prv[i]=i;
        for(int j=lg2[n];j>=0;j--){
            if(nxt[i]+power[j]>n) continue;
            if(x[nxt[i]+power[j]]-x[i]<=d) nxt[i]+=power[j];
        }
        if(nxt[i-1]==i) ed[i]=true;
    }
    if(c==11||c==12){
        solveA();
        return;
    }
    if(c==13||c==14){
        solveB();
        return;
    }
    for(int i=n;i>=1;i--)
        if(ed[nxt[i]]) nxt[i]=nxt[nxt[i]];
    for(int i=1;i<=n;i++){
        prv[i]=i;
        for(int j=lg2[n];j>=0;j--){
            if(prv[i]-power[j]<1) continue;
            if(nxt[prv[i]-power[j]]>=i) prv[i]-=power[j];
        }
    }
    int ans=0;
    //for(int i=1;i<=n;i++) cout<<nxt[i]<<' '<<prv[i]<<endl;
    for(int i=2;i<=n;i++){
        ans+=max(0ll,(prv[i+1]-prv[i])*(nxt[i-1]-nxt[i-2]));
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    for(int i=1,j=0;i<=2000000;i*=2,j++)
        power[j]=i;
    for(int i=1,j=0;i<=2000000;i++){
        if(i==power[j+1]) j++;
        lg2[i]=j;
    }
    while(t--) solve();
    return 0;
}
//Blue
//Oct31==Dec25?
