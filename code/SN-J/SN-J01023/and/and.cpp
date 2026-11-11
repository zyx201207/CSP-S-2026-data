#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=0,minn=20000000;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i]&minn,maxx&minn);
		minn=min(a[i]&maxx,minn&maxx);
	}
	cout<<maxx;
}
