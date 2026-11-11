#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+5,M=25,Q=505;

struct k{
    ll co,to;
};

ll n,m,t,ans,q,p,d,e,mx;
ll va[N],r[N],f[Q][Q];
k x[N][M];

int main(){
	ios::sync_with_stdio(0);	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>t>>m>>n>>mx>>q;
    for(int i=1;i<=n;i++){
        cin>>va[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=1e18;
        }
        f[i][i]=0;
    }
	for(int i=1;i<=m;i++){
        cin>>p;
        for(int j=1;j<=p;j++){
            k u;    u.to=i;
            cin>>d>>u.co;
            for(int p=1;p<=r[d];p++){
                f[x[d][p].to][i]=min(f[x[d][p].to][i],u.co+x[d][p].co);
            }
            x[d][++r[d]]=u;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            f[j][i]=f[i][j];
        }
    }
    for(int p=1;p<=m;p++){
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=q;i++){
        cin>>d>>e;
        if(d>e) swap(d,e);
        ll an=va[d]+va[e],ans=1e18;
        for(int j=1;j<=r[d];j++){
            for(int p=1;p<=r[e];p++){
                ans=min(ans,an+x[d][j].co+x[e][p].co+f[x[d][j].to][x[e][p].to]);
            }
        }
        cout<<ans<<"\n";
    }

	return 0;
}