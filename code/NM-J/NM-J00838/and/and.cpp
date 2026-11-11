#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,b[200005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=m;i++){
		b[i]=a[i];	
	}
	for(int i=2;i<=m;i++){
		ans=b[i]&b[i-1];
	}
	cout<<ans;
	return 0;
}
