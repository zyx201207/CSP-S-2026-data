#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char s[1000006];
int maxn=-1;
string e;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		int q=a[i];
		string w;
		while(q>=2)
		{
			w+=(q%2+'0');
			q/=2;
		}
		w+=(q+'0');
		if(i==1)
		{
			e=w;
		}
		else
		{
			string p;
			for(int j=0;j<min(w.size(),e.size());j++)
			{
				if(e[j]=='1'&&w[j]=='1')
				{
					p+='1';
				}
				else
				{
					p+='0';
				}
			}
			e=p;
		}
	}
	if(n!=m)
	{
		cout<<maxn;
		return 0;
	}
	if(n==m)
	{
		int k=0;
		int j=1;
		for(int i=0;i<e.size();i++)
		{
			k+=(e[i]-'0')*j;
			j*=2;
		}
		cout<<k;
	}
}
