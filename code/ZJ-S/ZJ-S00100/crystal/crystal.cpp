#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500050],ans,c[500050];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=a[2]-a[1];
		for(int t=n;t>=1;t--)
			if((t-1)*t*k/2<=m){
				cout<<t;
				return 0;
			}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i-1]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		int s=0,k=0;
		for(int j=i-1;j>=1;j--){
			k+=c[j];
			s+=k;
			if(s<=m)ans=max(ans,i+1-j);
			else break;
		}
	}
	cout<<ans;
	return 0;
}

