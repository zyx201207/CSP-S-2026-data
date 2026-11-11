#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct node {
	long long a,p;
} a[200005];
long long qw(long long x) {
	long long ans=0;
	while(x) {
		if(x%2==1) {
			ans++;
		}
		x/=2;
	}
	return ans;
}
bool cmp(node A,node B) {
	if(A.p==B.p) {
		return A.a>B.a;
	}
	return A.p>B.p;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i].a;
		a[i].p=qw(a[i].a);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].a;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i].a<<" ";
//	}
	for(long long i=2; i<=m; i++) {
		ans&=(a[i].a);
	}
	cout<<ans;
	return 0;
}

