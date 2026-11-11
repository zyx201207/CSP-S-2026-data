#include <bits/stdc++.h>
using namespace std;
const int MX=1e6+10;
unsigned long long a[MX],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
} 
