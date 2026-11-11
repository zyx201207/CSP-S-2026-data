#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
long long a[200005];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=n;j>=n-m+1;j--){
		ans=min(a[j],a[j+1]);
	}
	cout<<ans;
	return 0;
} 
