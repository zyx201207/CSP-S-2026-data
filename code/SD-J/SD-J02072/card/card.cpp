#include<bits/stdc++.h>
using namespace std;
string shan(string s,int a)
{
	string s1="";
	for(int  i=0;i<a;i++)
	{
		s1+=s[i];
	}
	return s1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a,b;
	string s="";
	cin>>a>>b;
	int arr[a];
	int brr[b];
	for(int i=0;i<a;i++)cin>>arr[i];
	for(int i=0;i<b;i++)brr[i]=0;
	for(int i=0;i<a;i++)
	{
		s="";
		for(int j=i;j<a;j++)
		{
			for(int y=0;y<s.size();y++)
			{
				if(s[y]-'0'==arr[j])
				{
					s=shan(s,y);
					break;
				}
			}
			s=s+char(arr[j]+'0') ;
		}
		for(int j=0;j<s.size();j++)
		{
			brr[s[j]-'0'-1]++;
		}
	}
	for(int i=0;i<b;i++)cout<<brr[i]<<" ";
}
