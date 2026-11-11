#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i]&a[i+1];
	for(int i=1;i<=n;i++)mx=max(b[i],mx);
	cout<<mx;
	return 0;
}