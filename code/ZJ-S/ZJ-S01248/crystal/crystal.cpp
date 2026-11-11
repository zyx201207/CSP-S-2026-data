#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005],s[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+b[i];
		b[i]=b[i-1]+b[i]*i;
	}
	int r=0,ans=-1;
	for(int i=1;i<=n;i++){
		while(b[r]-b[i-1]-(i-1)*(s[r]-s[i-1])<=m&&r<=n)r++;
		r--;
		if(b[r]-b[i-1]-(i-1)*(s[r]-s[i-1])<=m)ans=max(ans,r-i+1);
	}
	cout<<ans+1;
	return 0;
}