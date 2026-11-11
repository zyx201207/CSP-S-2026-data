#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long m;
long long a[500005];
int main(){
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long s=0;
	for(int i=n,j=n;i>=1;){
		while(s+(a[i]-a[j-1])<=m&&j-1>0){
			j--;
			s+=(a[i]-a[j]);
		}
		ans=max(i-j+1,ans);
		s-=(a[i]-a[i-1])*(i-j+1);
		i--;
	}
	cout<<ans;
	return 0;
}
