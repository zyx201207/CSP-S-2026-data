#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int ans=0;
	ans=a[n];
	for(int i=n-1,j=1;j<m;j++,i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
