#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[2000005];
vector<int> v[2000005];
int sum,mi;
void dfs1(int s,int e,int len){
	if(s==e){
		mi=min(mi,len);
		return;
	}
	for(auto i:v[s]){
		dfs1(i,e,len+1);
	}
}
void dfs2(int s,int e,int len){
	if(s==e){
		if(len==mi)sum++;
		return;
	}
	for(auto i:v[s]){
		dfs2(i,e,len+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			v[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int x=upper_bound(a+1,a+n+1,a[i]+d)-a;
			for(int j=i+1;j<x;j++){
				v[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;mi=INT_MAX;
				dfs1(i,j,0);
				dfs2(i,j,0);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

