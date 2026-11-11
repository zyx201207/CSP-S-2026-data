#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n,f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	f[0]=1073741823;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
	cout<<f[m];
	return 0;
}
