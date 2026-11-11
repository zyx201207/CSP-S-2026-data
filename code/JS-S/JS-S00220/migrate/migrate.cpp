#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=305;
ll c,T,n,d,res,vis[M],x[N],f[M][M];
void solveA(){
    ll dt=x[2]-x[1];
    if(dt>d){
        cout<<"0\n";
        return;
    }
    ll cnt=d/dt;
    ll L=cnt+1,R=cnt*2-1;
    ll ans=0;
    for(int i=n-R;i<=n-L;i++) ans+=i;
    cout<<ans<<'\n';
    return;
}
void solveB(){
    ll mus=0;
    for(int i=2;i<=n;i++){
        ll cur=x[i];
        int idx=lower_bound(x+1,x+1+n,cur-d)-x;
        mus+=i-idx;
    }
    ll ans=n*(n-1)/2-mus;
    cout<<ans<<'\n';
    return;
}
bool chk(int l,int r){
    res=0;
    for(int i=l;i<=r;i++) vis[i]=0;
    for(int S=0;S<(1<<(r-l));S++){
        for(int i=0;i<=r-l-2;i++){
            if(S&(1<<i)) vis[i+l+1]=1;
        }
        vector<int>cc;
        for(int i=l+1;i<=r-1;i++){
            if(vis[i]) cc.push_back(i);
        }
        int flag=1;
        int cnt=cc.size();
        for(int i=1;i<cnt;i++){
            if(x[cc[i]]-x[cc[i-1]]>d) flag=0;
        }
        if(x[cc[0]]-x[l]>d||x[r]-x[cc[cnt-1]]>d) flag=0;
        if(flag&&cnt==f[l][r]-1) res++;
    }
    return res==2;
}
void calc(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=2e9;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d) f[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //cout<<i<<' '<<j<<'\n';
            if(chk(i,j)) ans++;
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12) solveA();
        else if(c==13||c==14) solveB();
        else calc();
    }
    return 0;
}
