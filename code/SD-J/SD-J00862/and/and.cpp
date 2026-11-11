#include<bits/stdc++.h>
using namespace std;
int a[200110];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w".stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int maxn=a[n-1];
	for(int j=n-2;j>=n-m;j--){
		maxn=(maxn&a[j]);
	}
	cout<<maxn;
	return 0; 
} 
