#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
const int inf=1e18;
const int mod=998244353;
int c,t,n,d;
int a[N];
int ans;
map<pii,int>mp;

int dis[3010][3010];
vector<pii> v[N];
void dfs(int pos,int now,int last,int res){
	if(res>d) return ;
	for(pii it:v[now]){
		if(it.first==last) continue;
		if(res+it.second<=d){
			dis[pos][it.first]=res+it.second;
			mp[{pos,res+it.second}]++;
			if(mp[{pos,res+it.second}]==2) ans++;
			else if(mp[{pos,res+it.second}]==3) ans--;
			//cout<<pos<<' '<<now<<' '<<last<<' '<<res+it.second<<'\n';
			dfs(pos,it.first,now,res+it.second);
		}
		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) v[i].push_back({j,a[j]-a[i]});
				else break;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++){
			ans=0;mp.clear();
			dfs(i,i,0,0);
			res+=ans;
		}
		cout<<res;
	} 




	return 0;
}/*
0 1 
5 3 
-2 -1 0 1 2


*/

