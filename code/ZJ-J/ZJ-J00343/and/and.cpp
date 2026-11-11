#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],f[2010][2010],b1[32],ans=2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f,-1,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(n>2000){
		for(int i=1;i<=m;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int st=n;st>=0;st--)
		f[0][st]=a[st];
	for(int x=1;x<=m;x++)
		for(int st=n;st>=0;st--)
			for(int i=st+1;i<=n;i++)
				f[x][st]=max(f[x][st],f[x-1][i]&a[i]);
	cout<<f[m][0];
	return 0;
}