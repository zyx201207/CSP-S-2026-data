#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string> a(n,"");
	int x,maxx=0;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		while (x!=0)
		{
			a[i].push_back((x&1)+'0');
			x>>=1;
		}
		maxx=max(maxx,(int)a[i].size());
	}
	for (int i=0;i<n;i++)
	{
		for (int j=a[i].size();j<maxx;j++)
			a[i].push_back('0');
		reverse(a[i].begin(),a[i].end());
	}
	vector<bool> use(n,true);
	string ans="";
	bool flag=false;
	for (int j=0;j<maxx;j++)
	{
		int tmp=0;
		for (int i=0;i<n;i++)
			tmp+=(a[i][j]-'0')*use[i];
		ans.push_back((tmp>=m)+'0');
		if (tmp>=m) flag=true;
		if (flag)
			for (int i=0;i<n;i++)
				use[i]=use[i]&&(a[i][j]-'0');
	}
	int res=0;
	for (int i=0;i<maxx;i++)
		res=res*2+ans[i]-'0';
	cout<<res;
	return 0;
}
