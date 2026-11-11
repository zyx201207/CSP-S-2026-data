#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	long long i,j;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1,j=1;i<=n;(m+=(a[j]-a[i])),i++){
		while((a[j+1]-a[j])*(j-i+1)<=m&&j+1<=n)m-=(a[j+1]-a[j])*(j-i+1),j++;
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
