#include <bits/stdc++.h>
using namespace std;

long long n,m,ans,idx;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];	
	sort(a,a+n);
	int c[n]={0};
	for(int i=1;i<=n;i++)
		c[i]=a[i]-a[i-1];
	while(ans<=m){
		idx++;
		ans+=idx*c[idx];
	}
	cout<<idx;
	return 0;
}
