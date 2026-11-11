#include<bits/stdc++.h>
using namespace std;
int n,x;
long long a[200010],d[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-x+1;i++){
		d[i]=a[i]&a[i+1];
		for(int j=2;j<x;j++){
			d[i]=d[i]&a[i+x];
		}
	}
	sort(d+1,d+n+1);
	cout<<d[n];
	return 0;
}
