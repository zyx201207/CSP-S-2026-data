#include<bits/stdc++.h>
using namespace std;
int m,n,a[3010],b[200010];
int find1(string s,char c)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==c)return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		string s="";
		for(int j=i;j>=n;j++)
		{
			if(find1(s,'0'+b[j])==-1)
			{
				s+='0'+b[j];
			}
			else {
				s.erase(s.find('0'+b[j])+1);
			}
		}
		cout<<s<<' ';
		for(int j=1;j<s.size();j++)
		{
			a[s[j]-'0']++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i];
	}
	return 0;
}
