#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],sum[N],ans=1,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(long long i=1;i<n;i++){
		if(n-i+1<=ans)
			break;
		for(long long r=i+1;r<=n;r++){
			if(r-i+1<=ans)
				continue;
			long long nl=(a[r]*(r-i+1))-sum[r]+sum[i-1];
			if(nl<=m)
				ans=max(ans,r-i+1);
			else
				break;
		}
	}
	cout<<ans;

return 0;
}
