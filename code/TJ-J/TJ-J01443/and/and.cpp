#include<bits/stdc++.h>
using namespace std;
int n,a[200086],ans,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		ans=a[i];
		for(int j=i;j<=n;j++){
			ans=max(ans,ans&i);
		}
	}
	cout<<ans;
	return 0;
}
