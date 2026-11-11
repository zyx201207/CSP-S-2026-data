#include <bits/stdc++.h> 
using namespace std;
const long long N=1e7;
long long n,m,a[N],maxn,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n-m;i++){
		t=a[i+1];
		for (int j=i+1;j<=i+m;j++){
			t=t&a[j];
		}
		maxn=max(t,maxn);
	}
	cout<<maxn;
	return 0;
}
