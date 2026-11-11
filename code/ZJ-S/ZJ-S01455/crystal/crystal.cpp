#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500010],ans=1,s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int l=1,r=1;r<=n;r++,s+=(r-l)*(a[r]-a[r-1])){
		while(s>m&&l<r)s-=a[r]-a[l++];
		ans=max<long long>(ans,r-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}