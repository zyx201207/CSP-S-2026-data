#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[500010];
long long s[500010];
long long ss[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i]-a[i-1];
		ss[i]=ss[i-1]+(a[i]-a[i-1])*(i-1);
	}
	long long x=1,y=2;
	while(x<=n&&y<=n&&x<y){
		long long t=ss[y]-ss[x]-(x-1)*(s[y]-s[x]);
		if(t<=m){
			ans=max((y-x+1),ans);
			y++;
		}else if(t>m){
			x++;
		}
	}
	cout<<ans;
	return 0;
}
