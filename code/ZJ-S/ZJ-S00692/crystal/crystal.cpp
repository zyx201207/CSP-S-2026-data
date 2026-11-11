#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
long long m,a[500005],now;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;j<=n;j++){
		now+=(j-i)*(a[j]-a[j-1]);
		for(;now>m;now-=a[j]-a[i++]);
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
