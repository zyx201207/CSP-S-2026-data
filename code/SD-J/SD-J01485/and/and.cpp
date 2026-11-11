#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-0x3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=a[1];
	for(int i=2;i<=n;i++) x=x&a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxx=max(maxx,a[i]&a[j]);
		}
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==2) cout<<maxx;
	else if(m==n) cout<<x;
	else cout<<0;
	return 0;
} 
