#include <bits/stdc++.h>
using namespace std;
int a[200005];
//int b[35];


int main(){
	freopen("and4.in","r",stdin);
	//freopen("and.out","w",stdout);

	int n,m;cin>>n>>m;bool tag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]!=i-1)tag=0;
	}
	sort(a+1,a+n+1);
	if(tag) {
		cout<<a[n-m+1];
	}
	else cout<<a[n-m+1];
	return 0;
}
