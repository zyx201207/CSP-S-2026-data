#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int mx=1,t=1;
	long long p=0;
	for(int i=2;i<=n;i++){
		p+=(i-t)*(a[i]-a[i-1]);
		while(p>m && t<i)
			p+=a[t++]-a[i];
		mx=max(mx,i-t+1);
	}
	cout<<mx;
	return 0;
}
