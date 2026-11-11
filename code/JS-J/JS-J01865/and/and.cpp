#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
string zhan(int n)
{
	string t="";
	while(1)
	{
		t=t+to_string(n%2);
		n=n/2;
		if(n==1)
		{
			return t;
		}
		
	}
}
string pan(string a1,string a2)
{
	string ans;
	int qwe=max(a1.size(),a2.size());
	for(int k=1;k<=qwe;++k)
	{
		if(a1[k]==a2[k])
		{
			ans=ans+"1";
		}
		else
		{
			ans=ans+"0";
		}
	}
	return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+n+1,a+1);
	if(m==1)
	{
		cout<<a[1];
		exit(0);
	}
	else if(m==2)
	{
		cout<<pan(zhan(a[1]),zhan(a[2]));
	}
	
    return 0;
}
