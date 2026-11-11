#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,t,n,d,ans,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=1,r=l+4;
		for(l=1;l<=n-4;l++){
			for(r=l+4;r<=n;r++){
				if(abs(a[l+2]-a[l])<=d&&abs(a[r]-a[r-2])<=d){
					ans++;
				}
			}
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}
