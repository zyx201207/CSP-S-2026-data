#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int ans=-1;
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];	
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int ans1=a[i];
		for(int j=1;j<n;j++){
			ans1=ans1&a[i+j];
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}