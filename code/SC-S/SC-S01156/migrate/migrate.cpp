#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+10;
int x[N];
int cnt;
void dfs(int a,int b,int d,int n){
	if(a==b){
		cnt++;
		return;
	}
	for(int i=a+1;i<=n;i++){
		if(abs(x[a]-x[i])<=d){
			dfs(i,b,d,n);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dfs(i,j,d,n);
				if(cnt==2){
					ans++;	
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
