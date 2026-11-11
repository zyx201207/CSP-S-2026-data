#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long nmin=1000000000;
	if(m==n){
		for(long long i=1;i<=m;i++){
			nmin=min(nmin,a[i]);
		}
	}
	sort(a+1,a+n+1);
	for(long long i=n-m+1;i<=n;i++){
		nmin=min(nmin,a[i]);
	}
	cout<<nmin;
	return 0;
}
