#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<=(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,int> PLI;
typedef pair<int,ll> PIL;
const int MAXN = 2e6+10;

int n;ll d;
ll pos[MAXN];
int lf[MAXN],rf[MAXN],mlf[MAXN];
ll ln[MAXN],rn[MAXN];

bool check(int x, int y){
    if(x>=y)return false;
    return lf[y]==x&&rf[x]==y;
}

void getl(){
    rep(i,1,n){
        if(check(lf[i],i))ln[i]=ln[lf[i]]+1;
        else ln[i]=1;
        if(i<n)ln[i]+=max(0,lf[i+1]-1-lf[i]);
        //cerr<<"ln["<<i<<"]="<<ln[i]<<'\n';
    }
}

void getr(){
    per(i,n,1){
        if(check(i,rf[i]))rn[i]=rn[rf[i]]+1;
        else rn[i]=1;
        if(i>1)rn[i]+=max(0,rf[i]-1-rf[i-1]);
        //cerr<<"rn["<<i<<"]="<<rn[i]<<'\n';
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        //clear
        //pos[0]=-1e18;
        rep(i,1,n)cin>>pos[i];
        int x=1,y=1;
        while(x<=n){
            while(y<=n&&pos[y]-pos[x]<=d)++y;
            rf[x++]=y-1;
            //cerr<<"rf["<<x-1<<"]="<<y-1<<'\n';
        }
        x=n;y=n;
        while(y>=1){
            while(x>=1&&pos[y]-pos[x]<=d)--x;
            mlf[x+1]=y;
            lf[y--]=x+1;
            //cerr<<"lf["<<y+1<<"]="<<x+1<<'\n';
        }
        getl();getr();
        ll ans=0;
        rep(i,1,n){
            int a1,a2,a3,a4;
            a1=i;
            a2=rf[a1];
            a3=a2-1;
            a4=mlf[a3];
            if(a1>=a3)continue;
            if(a3>=a2)continue;
            if(a2>=a4)continue;
            //if(!check(a1,a2))continue;
            //if(lf[a4]!=a3)continue;
            //if(lf[a3]<a1)continue;
            //if(rf[a2]>a4)continue;
            //cerr<<a1<<' '<<a4<<" ok\n";
            if(lf[a3]==a1&&rf[a2]==a4)ans+=ln[a1]*rn[a4];
            else if(lf[a3]==a1)ans+=ln[a1];
            else if(rf[a2]==a4)ans+=rn[a4];
        }
        cout<<ans<<'\n';
    }
    return 0;
}