#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
int n,m;
int f[2500][N];
string to_2(int x)
{
	if(x<=0)return "";
	if(x%2==1)return to_2(x/2)+"1";
	else return to_2(x/2)+"0";
}
int to_10(string x)
{
	int ans=0,p=1;
	for(int i = x.size()-1;i >= 0;i--)
	{
		ans+=(x[i]-'0')*p;
		p*=2;
	}
	return ans;
}
int and_(int x,int y)
{
	string ans;
	string xx = to_2(x);
	string yy = to_2(y);
	if(xx.size()<yy.size())
		while(xx.size()!=yy.size())
			xx="0"+xx;
	if(xx.size()>yy.size())
		while(xx.size()!=yy.size())
			yy="0"+yy;
	for(int i = xx.size()-1;i >= 0;i--)
	{
		if(xx[i]=='1'&&yy[i]=='1')ans="1"+ans;
		else ans = "0"+ans;
	}
	return to_10(ans);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		f[1][i]=max(f[1][i-1],a[i]);
	}
	for(int i = 2;i <= m;i++)
	{
		for(int j = i;j <= n;j++)
		{
			f[i][j]=max(f[i][j-1],and_(f[i-1][j-1],a[j]));
		}
	}
	cout << f[m][n];
}
