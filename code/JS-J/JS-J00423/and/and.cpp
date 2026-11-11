#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>n-m;i--)ans&=a[i];
	cout<<ans;
}
