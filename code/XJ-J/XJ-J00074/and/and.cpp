#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],b[N];
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int z=a[n];
		for(int i=1;i<n;i++){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		b[i]=(a[i]&a[i+1]);
	}
	cout<<b[n-m+1];
	return 0;
}
