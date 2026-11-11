#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			sum^=a[j];
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}//2
