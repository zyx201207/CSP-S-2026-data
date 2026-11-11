//严禹皓 西安交通大学附属中学 SN-J00806 
#include<bits/stdc++.h>
using namespace std;
char a[500005];
vector<string>v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s="";
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}	
	for(int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			char c=a[j];
			int x=0;
			for (int k=0;k<s.size();k++)
			{
				char t=s[k];
//				cout << (c==t)<<"\n";
				if(c==t)
				{
					x=k+1;
				}
			}
//			cout << x << "\n";
			if(x!=0)
			{
				s.erase(x,n-x);
			}
			else
			{
				s+=c;
			}
//			cout << s << "\n";
//			cout <<x<<"\n";
		}
		v.push_back(s);
		s="";
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		for(auto s:v)
		{
			char c=char(i+48);
			if(s.find(c)>=0)
			{
				cnt++;
				break;
			}
		}
		cout << cnt-1 << "\n";
		cnt=0;
	}
	return 0;
}

