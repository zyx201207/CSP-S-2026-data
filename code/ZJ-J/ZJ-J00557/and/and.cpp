#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],b[N][35],ans[N],ansx[N],anssum,x,len;
signed main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[i];len=0;
		while (x) b[i][++len]=x%2,x/=2;
	}
	for (int i=32;i>=1;i--)
	{
		if (anssum<m)
		{
			anssum=0;
			for (int j=1;j<=n;j++)
				if (b[j][i]==1) ans[++anssum]=j;
			if (anssum==m) break;
		}
		else
		{
			x=0;
			for (int j=1;j<=anssum;j++)
				if (b[ans[j]][i]==1) ansx[++x]=ans[j];
			if (x>m)
			{
				for (int j=1;j<=x;j++) ans[j]=ansx[j];
				anssum=x;
			}
			else if (x==m)
			{
				for (int j=1;j<=x;j++) ans[j]=ansx[j];
				anssum=x;
				break;
			}
		}
	}
	if (anssum<m) cout<<"0";
	else
	{
		x=a[ans[1]];
		for (int i=2;i<=anssum;i++) x=x&a[ans[i]];
		cout<<x;
	}
	return 0;
}
