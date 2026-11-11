#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	z=a[0];
	for(int i=0;i<m;i++){
		z=z&a[i];
	}
	cout<<z;
	return 0;
}
