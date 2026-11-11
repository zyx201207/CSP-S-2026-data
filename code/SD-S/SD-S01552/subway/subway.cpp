#include <bits/stdc++.h>
using namespace std;
int m,q,c,n,d,cnt;
int w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005],ch[500005];
long long s=1e17,minn=0;
bool check(int x)
{
	if(x==ch[x]) return false;
	ch[x] = x;
	return true;
}
void dfs(int s, int e)
{
	if(s==e) return; 
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=2;j++) 
		{
			if(a[i][j]==s) 
			{
				if(j==1) if(check(a[i][2])) minn+=t[i][j]+t[i][2],dfs(a[i][2],e);
				else if(check(a[i][1])) minn+=t[i][j]+t[i][1],dfs(a[i][1],e); 
				memset(ch,0,sizeof(ch));
				if(minn<s)
				{
					s = minn;
					minn = 0;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i =1;i<=m;i++) cin >> w[i];
	for(int i = 1;i<=n;i++)
	{
		cin >> k[i];
		for(int j = 1;j<=k[i];j++) 
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i<=q;i++) cin >> x[i] >> y[i];
	for(int r = 1;r<=q;r++)
	{
		dfs(x[r],y[r]);
		cout << s << endl;
	}
	return 0;
}
