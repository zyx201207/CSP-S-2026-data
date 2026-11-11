#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,num=0;
bool f;
string s[200005];
bool cmp(string a,string b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		y=pow(2,29);
		while(y>0)
		{
			if(x>=y)
			{
				s[i]+='1';
				x-=y;
			}
			else
			{
				s[i]+='0';
			}
			y/=2;
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=0;i<30;i++)
	{
		y=pow(2,29-i);
		f=true;
		for(int j=1;j<=m;j++)
		{
			if(s[j][i]=='0')
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			num+=y;
		}
	}
	cout<<num;
	return 0;
} 
