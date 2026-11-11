#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long z=0,ma=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		z=z and a[i];
		ma=max(ma,a[i]);
	}
	if(n==m){
		cout<<z;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	cout<<a[n-1];
	return 0;
}
