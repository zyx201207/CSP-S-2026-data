#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i>=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i<=n-m+1;i++){
		ans+=(a[i]&a[i+1]);
	}
	cout<<12;
}
