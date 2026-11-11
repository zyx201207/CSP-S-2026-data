#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,d,vis[5005],v[5005];
void dfs(int x,int sum,int l,int r){
	if(sum+l>r){
		ans++;
		return ;
	}
	for(int i=1;i<=d;i++){
		vis[x]=i;
		dfs(x+1,sum+i,l,r); 
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin>> v[i];
		}
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				dfs(1,0,v[i],v[j]);
				if(ans==2){
					num++;
				}
			}
		}
		cout <<num << "\n";
	}
	return 0;
}  
