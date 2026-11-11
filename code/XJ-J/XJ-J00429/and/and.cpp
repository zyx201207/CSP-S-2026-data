#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s1,s2,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=m;i++){
		s1=a[n-i];
		if(i==1)s2=a[n-i-1];
		else s2=ans;
		ans=s1&s2;
	}
	cout<<ans;
	return 0;
}