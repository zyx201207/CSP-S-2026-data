#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
vector<int> g[N];
map<int,int> mp;
int mn=INT_MAX;
void dfs(int x,int y,int sum){
	if(x==y){mp[sum]++;mn=min(mn,sum);}
	for(int i=g[x].size()-1;i>=0;i--){
		dfs(g[x][i],y,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		unsigned long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d)g[j].push_back(i);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				dfs(i,j,0);
				if(mp[mn]==2)cnt++;
				mp.clear();
				mn=INT_MAX;
			}
		}
		cout<<cnt<<"\n";
		for(int i=1;i<=n;i++){
			if(g[i].size()!=0)g[i].clear();
		}
	}
	return 0;
}