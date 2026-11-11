#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t=1;
	cin>>n>>m;
	int a[1000000],b[1000000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		int o=a[i];
		for(int j=1;j<m;j++){
			o&=a[i+j];
		}
		b[t++]=o;
	}
	sort(b+1,b+t);
	cout<<b[t-1];
	return 0;
}
