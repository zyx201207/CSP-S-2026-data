#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i= 1;i<= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	ans=a[n];
	for(int i = n-1;i>=n+1-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
