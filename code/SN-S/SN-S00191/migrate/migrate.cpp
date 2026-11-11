#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int t,c,n,k,a[N],sum,cnt;
void dfs(int x,int y,int f,int an){
	if(f==y){
		if(an==sum) cnt++;
		if(an>sum) return;
		if(an<sum){
			sum=an;
			cnt=1;
		}
	}
	for(int i=f+1;i<=y;i++){
		if(a[i]-a[f]>k) return;
		else dfs(x,y,i,an+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=1e18;cnt=0;
				dfs(i,j,i,0);
				if(cnt==2) ans++; 
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	
	return 0;
}
