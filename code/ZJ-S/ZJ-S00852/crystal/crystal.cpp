#include <bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],ml,ans,l,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		ans=a[i]*(i-l-1)-c[i-1]+c[l];
		while(ans>m){
			ans=ans-a[i]+a[++l];
		}
		ml=max(ml,i-l);
	}
	cout<<ml;
	return 0;
}