#include<bits/stdc++.h>
using namespace std;
int find1(string s,int i)
{
	int ans=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]==to_string(i))
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=s.size();i++)
	{
		if(find1(s,i)>1)
		{
			s-=s.substr(i+1,size()-1);
		}
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}