#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=200005;
long long n,m;
long long a[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f[1]=a[n];
	cout<<a[n-m+1];
	return 0;
}
