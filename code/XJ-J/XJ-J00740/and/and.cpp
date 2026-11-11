#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,maxa,a[]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=1;
	while(q<=n-m+1){
		for(int i=2;i<=m;i++){
			maxa=a[q]&a[q+1];
			q+1;
	}
	}
	return 0;
}