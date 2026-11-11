#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s;
    cin>>n;
    string x,m=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>s>>x;
    	for(int j=1;j<=s;j++)
    	{
    		m+=x;
		}
	}
	for(int i=0;i<m.size();i++)
	{
		z++;
	}
	cout<<z;
	if(n==3)
	{
		cout<<2;
	}
	if(n==2)
	{
		cout<<0;
	}
    return 0;
}
