#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int c,t,n,d,x[N],s[N],ss,cnt,ans;
vector<int>v[N];
void dfs1(int x,int f,int y,int o){
	if(x==y){
		ss=min(ss,o);
		return;
	}
	for(auto i:v[x]){
		if(i==f) continue;
		dfs1(i,x,y,o+1);
	}
}
void dfs2(int x,int f,int y,int o){
	if(x==y){
		if(o==ss) cnt++;
		return;
	}
	for(auto i:v[x]){
		if(i==f) continue;
		dfs2(i,x,y,o+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i]; 
		for(int i=2;i<=n;i++) s[i]=s[i-1]+(x[i]-x[i-1]);
		for(int i=1;i<=n;i++){
			v[i].clear();
			for(int j=i+1;j<=n;j++){
				if(s[j]-s[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				ss=n,cnt=0;
				dfs1(i,0,j,0);
				dfs2(i,0,j,0);
				if(cnt==2) ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
