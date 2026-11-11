#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,l,r,t,w,sum,a[200010];
char c[200010];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(i=1; i<=n; i++)cin>>a[i]>>c[i];
	t=1,
	w=n,
	l=a[t],
	r=a[w];
	while(t<=w) {
		if(c[t]!=c[w])sum+=min(l,r);
		if(l<r)t++,r-=l,l=a[t];
		else if(l>r)w--,l-=r,r=a[w];
		else t++,w--,l=a[t],r=a[w];
	}
	cout<<sum;
}