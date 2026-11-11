#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,sum=-6767,cnt,maxn=-6767;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[m];
	return 0;
}
/*
5 3
31 3 1 15 7

*/
