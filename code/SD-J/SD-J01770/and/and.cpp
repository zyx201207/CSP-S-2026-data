#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+1],maxn=-2147;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	return 0;
}

