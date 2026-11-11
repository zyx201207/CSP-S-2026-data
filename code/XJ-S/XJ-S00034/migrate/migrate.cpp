#include <bits/stdc++.h>
using namespace std;

const int N=2e6+10;

int xb[N];
vector<int>g[N];
long long ans,cnt;
int mn=INT_MAX;

void dfs (int u,int t,int step){
	if (step>mn){
		return ;
	}
	if (u==t){
		if (step==mn)
			cnt++;
		else {
			mn=step;
			cnt=1;
		}
		return ;
	}
	for (auto v:g[u]){
		dfs(v,t,step+1);
	}
}

int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while (t--){
		int n,d;
		cin >>n>>d;
		for (int i=1;i<=n;i++){
			cin >>xb[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i-1;j>=1;j--){
				if (xb[i]-xb[j]<=d){
					g[j].push_back(i);
				}
			}
		}
		cnt=0;
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				dfs(i,j,1);
				if (cnt==2){
					ans++;
//					cout <<i<<' '<<j<<'\n';
				}
			}
		}
		cout <<ans;
	}
	
	return 0;
}
