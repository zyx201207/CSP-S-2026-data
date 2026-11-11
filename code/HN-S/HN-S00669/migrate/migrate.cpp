#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;

//#define int long long
int n,m,a[N];
map<int,int> Map;
void dfs(int u,int sum,int r){
	if(u>n) return ;
	if(u==r){
		Map[sum]++;
		return ;
	}
	for(int i=u+1;i<=r;i++){
		if(a[i]-a[u]<=m) dfs(i,sum+1,r);
	}
}
//unsigned
int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int x,t;
	cin>>x>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,0,j);
				sum+=(Map.begin()->second==2);
				Map.clear();
			}
		}
		cout<<sum<<"\n";		
	}

	return 0;
}

