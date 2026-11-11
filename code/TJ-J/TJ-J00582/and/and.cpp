#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],mx=-1e9+5,m;
/*
5 3
31 3 1 15 7
*/
int main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		mx=max(a[i]&a[i+1],mx);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
