#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	cout<<ans;
	return 0;
}
