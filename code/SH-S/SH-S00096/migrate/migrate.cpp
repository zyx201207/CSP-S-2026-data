#include<bits/stdc++.h>
using namespace std;
void init_cin(){
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
}
typedef long long ll;
int C,t,n;
ll a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	init_cin();
	cin>>C>>t;
	while(t--){
		int n;
		ll m;
		cin>>n>>m;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int l=0;
				for(int k=i+1;k<j;k++){
					if(a[j]-a[k]<=m&&a[k]-a[i]<=m&&a[j]-a[i]>m){
						l++;
					}
				}
				if(l==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
