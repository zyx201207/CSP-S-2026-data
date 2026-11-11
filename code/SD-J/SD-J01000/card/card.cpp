#include<bits/stdc++.h> 
using namespace std;
long long maxn,n,m,b[500005];
long long a[500005],cnt[300005],pos[300005];
string s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s.clear();
		for(int j=1;j<=m;j++)
		{
			pos[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			pos[a[j]]++;
			if(pos[a[j]]>=2)
			{
				s.erase(s.find(a[j]+'0'));
				s+=a[j]+'0';
			}
			else if(pos[a[j]]==1) 
			{
				s+=a[j]+'0';
			}	
		}
		for(int j=0;j<s.size();j++)
		{
			b[j]=s[j]-'0';
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<s.size();k++)
			{
				if(b[k]==j)
				{
					cnt[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
