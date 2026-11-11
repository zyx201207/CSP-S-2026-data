#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,ll>
using namespace std;
const int N=1010;
const ll inf=1e18;
ll n,m,d,q,c,w[500010],dis[N][N],t[N][N],k[N];
vector<PII> vec[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
			ll x,y;
			cin>>x;
			cin>>y;
			vec[x].push_back({i,y});
        }
        /*for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++){
                if(j==l) continue;
                dis[a[i][j]][a[i][l]]=min(dis[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
                dis[a[i][l]][a[i][j]]=dis[a[i][j]][a[i][l]];
            }
        */
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=dis[j][i]=inf;
        }
    }
    for(int i=1;i<=m;i++){
		dis[i][i]=0;
	}
    for(int i=1;i<=n;i++){
        for(auto j:vec[i]){
            int v=j.first;
            ll w=j.second;
            for(auto l:vec[i]){
                int v2=l.first;
                ll w2=l.second;
                if(v==v2) continue;
                dis[v][v2]=min(dis[v][v2],w+w2);
                dis[v2][v]=dis[v][v2];
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=dis[i][j];
            }
        }
    }
    /*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
    while(q--)
    {
        ll s,t,ans=inf;
        cin>>s>>t;
        for(auto i:vec[s]){
            int v1=i.first,w1=i.second;
            for(auto j:vec[t]){
                int v2=j.first,w2=j.second;
                ans=min(ans,w1+w2+dis[v1][v2]+w[s]+w[t]);
            }
        }
        cout<<ans<<"\n";
    }
}
