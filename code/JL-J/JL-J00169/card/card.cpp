#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
map<char,int>num;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		a+=x;
	}
	for(int i=1;i<=n;i++)
	{
		string b="";
		map<char,int>mp;
		for(int j=0;j<n;j++)
			mp[a[j]]=-1;
		for(int x=i-1;x<n;x++)
		{
			if(mp[a[x]]==-1)
				b+=a[x],mp[a[x]]=x;
			else
			{
				for(int k=mp[a[x]];k<b.size();k++)
					mp[b[k]]=-1,b[k]='0';
				b+=a[x];
				mp[a[x]]=x;
			}
		//	cout<<b<<endl;
			//for(int i=1;i<=m;i++)
			//{
				//char xx=i+'0';
		//cout<<mp[xx]<<" ";
			//}
			//cout<<endl;
		}
		//cout<<b<<endl;
		for(int i=0;i<b.size();i++)
			num[b[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		char xx=i+'0';
		cout<<num[xx]<<" ";
	}
	return 0;
}
