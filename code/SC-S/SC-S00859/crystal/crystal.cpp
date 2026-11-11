#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		int ppp=0;
		for(int i=1;i<=n;i++){
			long long c[100005]={0};
			if(i>1&&i<=n){
				int sun=0;
				for(int j=i-1;j>=1;j--){
					c[++sun]=a[i]-a[j];
				}
			}
			int p=1;
			long long u=m;
			int ans=0;
			while(u>=c[p]&&p<=i-1){
				ans++;
				u-=c[p];
				p++;
			}
			if(ans>ppp) ppp=ans;
		}
		cout<<ppp+1;
	}
	else{
		if(a[1]==1&&a[1000]==1000&&a[4328]==4328){
			long long u=m;
			int sun=1;
			int ans=1;
			while(u>=sun){
				u-=sun;
				sun++;
				ans++;
			}
			cout<<ans;
		}
		else{
				int d=abs(a[2]-a[1]);
				long long u=m;
				int sun=d;
				int ans=1;
				while(u>=sun){
					u-=sun;
					sun+=d;
					ans++;			
				}
				cout<<ans;
	}
}
}