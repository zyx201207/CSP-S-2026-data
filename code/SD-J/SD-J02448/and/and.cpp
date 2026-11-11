#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		int t=a[i];
		for(int j=0;j<m;j++){
			t&=a[i+j];
		} 
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
} 
