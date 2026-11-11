#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m;
long long a[N],ans,s[N];
long long maxn;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i-1]&a[i];
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]&s[i]);
	}
	cout<<maxn;
	return 0;
}
