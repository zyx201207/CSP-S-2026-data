#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int C,T,n,ans,inf=2e6+10;
ll d,x[N];
int rmx[N],lmx[N],dis[N],c[N];
bool vis[N];
inline void query(int x){
    for(int i=1;i<=x+1;i++) vis[i]=c[i]=0,dis[i]=inf;
    vis[x]=1;;dis[x]=0;c[x]=1;c[x-1]=-1;
    int l=x;
    for(int i=x;i>=1;i--){
        c[i]=c[i]+c[i+1];
        if(i==x) l=x;
        else if(dis[i]!=dis[i+1]){
            l=i;
            while(dis[l-1]==dis[i]) l--; 
        }
        if(lmx[i]<=l-1) c[l-1]+=c[i],c[lmx[i]-1]-=c[i];
        if(i==x) for(int j=lmx[i];j<i;j++) dis[j]=dis[i]+1;
        else if(lmx[i]!=lmx[i+1]) for(int j=lmx[i];j<lmx[i+1];j++) dis[j]=dis[i]+1;
    }
    for(int i=1;i<=x;i++) if(c[i]==2) ans++;
    return;
}
inline void solve(){
    cin>>n>>d;ans=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    int r=1,l=n;
    for(int i=1;i<=n;i++){
        while(x[i]+d>=x[r+1]&&r<n) r++;
        rmx[i]=r;
    }
    for(int i=n;i>=1;i--){
        while(x[l-1]+d>=x[i]&&l>1) l--;
        lmx[i]=l;
    }
    for(int i=n;i>=1;i--) query(i);
    cout<<ans<<"\n";
    return;
}
void solve1(){
    cin>>n>>d;
    int gc;ans=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    gc=x[2]-x[1];
    int tc=d/gc;
    if(tc==1){
        cout<<"0\n";
        return;
    }
    for(int i=1;i<=n;i++)
        if(i+2*tc-1<=n) ans++;
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--){
        if(C<=10) solve();
        else if(C<=12) solve1();
    }
    return 0;
}