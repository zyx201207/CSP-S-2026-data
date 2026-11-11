#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long minn=0x3f3f3f3f3f3f3f3f;
		long long maxx=-2e18-5;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
			minn=min(minn,a[i]);
		}
		long long n2=n;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d){
				n2=i-1;
				break;
			}
		}
		long long sum=2*d-1;
		long long ans=0;
		for(int i=1;i<=n2;i++){
			if(i+sum>n2){
				break;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
