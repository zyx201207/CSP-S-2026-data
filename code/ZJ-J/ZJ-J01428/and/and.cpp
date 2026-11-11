#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1,k=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for (int i=2;i<=m;i++){
		k&=a[i];
	}maxn=k;
	for(int i=1;i<=n-m;i++){
		k&=(~a[i]);
		k&=a[i+m];
		maxn=max(maxn,k);
	}cout<<maxn;
	return 0;
} 
