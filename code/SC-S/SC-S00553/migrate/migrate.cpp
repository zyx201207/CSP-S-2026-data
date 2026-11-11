#include<bits/stdc++.h>
#define LL long long
#define fr first
#define sc second
using namespace std;
int n,ans;
LL d;
vector<LL>x;
vector<vector<int>>G;
vector<bool>vis;
vector<pair<int,int>>cnt;//cnt[v]{i,j}:到v距离最小i一共j个
inline void dfs(int u,int sum){
	auto &c=cnt[u];
	if(c.fr>sum) c.fr=sum,c.sc=1;
	else if(c.fr==sum) c.sc++;
	else return ;
	for(int v:G[u])
		dfs(v,sum+1);
}
void FlagA();
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		x.clear(),x.resize(n+1),G.clear(),G.resize(n+1);
		bool flagA=true;
		for(int i=1;i<=n&&cin>>x[i];i++)
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]) flagA=false;
		if(flagA) {FlagA();continue;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(llabs(x[i]-x[j])<=d)
					G[i].push_back(j),G[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			pair<int,int>tmp={1e9,-1};
			cnt.clear(),cnt.resize(n+1),fill(cnt.begin(),cnt.end(),tmp);
			dfs(i,0);
			for(auto [d,cnt]:cnt)
				if(cnt==2) ans++;
		}
		cout<<ans/2<<'\n';
		ans=0;
	}
	return 0;
}
void FlagA(){
	LL k=x[2]-x[1];
	if(k*2>d) return cout<<0<<'\n',void();
	cout<<max(n-int(d/k+d/k-1ll),0)<<'\n';
}