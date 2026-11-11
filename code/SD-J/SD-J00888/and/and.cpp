#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 int n,m;
	 long long maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]&a[i];
	}
	for(int i=m;i<=n;i++){
		maxn=max(maxn,a[i]&a[i-m+1]);
	}
	cout<<maxn;
	return 0;
} 
