#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,ans,a[N],b[N],cnt;
signed main(){
	freopen("crystal.out","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			if(i*(i+1)/2*b[2]>m){
				ans=i;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			cnt+=b[i];
		}
		if(cnt>m){
			ans=i-1;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
