#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x11=n,y11=m;
	long long a[200005],f[200005][200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i][1]=1;
		
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],(f[i-1][j-1]&a[i]));
		}	
	}
	cout<<f[x11][y11];
	return 0;
}
