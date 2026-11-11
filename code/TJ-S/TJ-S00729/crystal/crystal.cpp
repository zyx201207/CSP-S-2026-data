#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=5e5+10;

int n,m;
ll a[N];
ll sum[N];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	if(n<=5000){
		for(int r=1;r<=n;r++)
			for(int l=1;l<=r;l++)
				if((r-l+1)*a[r]-(sum[r]-sum[l-1])<=m)ans=max(ans,r-l+1);
		cout<<ans;
	}
	else{
		int k=a[2]-a[1];
		for(int len=1;len<=n;len++)if(k*len*(len+1)/2<=m)ans=max(ans,len);
		cout<<ans;
	}
	return 0;
}
