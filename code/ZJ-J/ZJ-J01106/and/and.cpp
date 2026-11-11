#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,maxn,a[200010];
void sc(int t,int s) {
	if(t>m) {
		maxn=max(maxn,s);
		return;
	}
	for(int i=t+1; i<=n; i++)sc(i,s&a[i]);
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n; i++)cin>>a[i];
	if(m==1) {
		int maxn=0;
		for(i=1; i<=n; i++)maxn=max(maxn,a[i]);
		cout<<maxn;
		return 0;
	} else if(m==n) {
		int sum=a[1];
		for(i=2; i<=n; i++)sum&=a[i];
		cout<<sum;
	} else if(m==2) {
		int j,maxn=0;
		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
		return 0;
	} else if(m==n-1) {
		int maxn=0;
		for(i=1; i<=n; i++) {
			int sum=a[(i==1?2:1)];
			for(int j=2; j<=n; j++)
				if(i!=j)sum&=a[j];
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	} else if(n<=20) {
		for(i=1; i<=n; i++)sc(i,a[i]);
		cout<<maxn;
	}
	for(i=1; i<=n; i++)
		if(a[i]!=i-1)break;
	if(i>n)cout<<n-m;
	else {
		int maxn=0;
		for(i=1; i<=n; i++)maxn=max(maxn,a[i]);
		cout<<maxn<<"\n";
	}
}