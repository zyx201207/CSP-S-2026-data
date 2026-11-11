#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
bool cmp(long long l,long long r) {
	return l>r;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		b[i]=b[i-1]+a[i];
	}
	int l=1;
	int ans=-1;
	for(int r=l; r<=n; r++) {
		if(a[l-1]*(r-l+1)-(b[r]-b[l-1])<=m&&a[l-1]*(r-l+1)-(b[r]-b[l-1])>0) {
			ans=max(ans,(r-l+2));
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
