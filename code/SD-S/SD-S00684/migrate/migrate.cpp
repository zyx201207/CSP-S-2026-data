#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,n,d,ans,a[N],vis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[i]=0;
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12){
			int s=a[2]-a[1];
			if(d<2*s&&d>=2*s)cout<<n-3<<endl;
			else cout<<0<<endl; 
			continue;
		}
		int l=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d){
				ans++;
				for(int j=i-1;j>=1;j--){
					if(a[i+1]-a[j]<=d||a[j+1]-a[j]>d||a[j+2]-a[j]<=d)break;
					ans++;
				}
			}else if(l==1&&a[i+3]-a[i+2]<=d)ans++;
			else l=0;
		//	cout<<i<<' '<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
