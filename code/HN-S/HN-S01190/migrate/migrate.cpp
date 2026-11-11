#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[2000010],cnt,ans;
bool f[2000010];
void dfs(int x,int y){
	for(int i=1;i<=n;i++){
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> t;
	while(t--){
		cnt=0;
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i>=j)continue;
				dfs(i,j);
			}
		}
	}
	return 0;
}

