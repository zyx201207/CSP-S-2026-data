#include<bits/stdc++.h>
using namespace std;
long long a[501000];
long long q[501000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n,m;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=a[i]+q[i-1];
	}
	int now=0;
	for(int i=1;i<=n;i++){
		long long cost=1ll*(i-1)*a[i]-q[i-1];
		if(cost<=m) now=i;
		else break;
	}
	cout<<now;
	return 0;
} 