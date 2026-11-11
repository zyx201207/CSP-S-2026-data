#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("ant.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	if(m==1){
		cout<<a[1];
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=max(ans,a[i-1]&a[i]);
	}
	cout<<ans;
	return 0;
}
