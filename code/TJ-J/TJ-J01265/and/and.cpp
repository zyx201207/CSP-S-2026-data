#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in.txt","r",stdin);	
	freopen("travel.out.txt","w",stdout);
	int a,b,f=0;
	cin>>a>>b;
	vector<int> c;
	for(int i=0;i<=a;i++)
	{
		int n;
		cin>>n;
		c.push_back(n);
	}
	sort(c.begin(),c.end());
	for(int i=0;i<b;i++)
	{
		f=c.at(c.size()-i)	and f;
	}
	cout<<f;}
