#include<bits/stdc++.h>
using namespace std;
#define int long long
/*====================*/
const int N=2e6+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
int n,d,a[N],b[N];
int dis[N],c[N];
vector<int> e[N];
/*====================*/
void Solve(){
	
	cin>>n>>d;
	int cntt=0;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=0,dis[i]=0,e[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)e[i].push_back(j);
			else break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[j]=INF,c[j]=0;
		dis[i]=0;
		queue<int> q;q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int i=0;i<e[x].size();i++){
				int y=e[x][i];
				if(dis[x]+1<dis[y])dis[y]=dis[x]+1,c[y]=1;
				else if(dis[x]+1==dis[y])c[y]++;
				if(dis[x]+1==dis[y])q.push(y);
			}
		}
		for(int j=1;j<=n;j++){
			if(c[j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
/*====================*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cc;
    cin>>cc;
	int T=1;cin>>T;
	while(T--)Solve();
	return 0;
}

