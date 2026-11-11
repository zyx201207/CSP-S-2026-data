#include<bits/stdc++.h>
using namespace std;
long long n,m,a[202000],ans;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=1;i<m;i++){
		ans=ans&a[n-i-1];
	}
	cout<<ans;
	return 0;
} 
