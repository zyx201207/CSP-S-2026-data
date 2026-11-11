#include<bits/stdc++.h>
using namespace std;
int num[1000000];
int res[1100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	bool f=1;
	for(int i=1;i<n;i++)
	{
		if(num[i]<num[i-1])
			f=0;
	}
	if(f)
	{
		for(int i=1;i<=m;i++)
			cout<<i<<' ';
		cout<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		string ans="";
		for(int j=i;j<n;j++)
		{
			char ch=num[j]+'0';
			int len=ans.size();
			if(len==0)
			{
				ans.push_back(ch);
				continue;
			}
			for(size_t t=0;t<ans.size();t++)
			{
				if(ans[t]==ch)
				{
					for(int x=t;x<len;x++)
						ans.pop_back();
				}
			}
			ans.push_back(ch);
		}
		for(size_t i=0;i<ans.size();i++)
			res[ans[i]-'0']++;
	}
	for(int i=1;i<=m;i++)
		cout<<res[i]<<' ';
	cout<<endl;
	
	
	return 0;
}
