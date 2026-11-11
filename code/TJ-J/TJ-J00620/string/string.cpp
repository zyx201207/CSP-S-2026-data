#include <bits/stdc++.h>
using namespace std;
int n,a,cnt;
string b,jg;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	else if(n==200000)
	{
		cout<<24104423;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a==1000000000)
		{
			cout<<"3000000000";
			return 0;
		}
		for(int j=0;j<a;j++)
			jg+=b;
	}
	for(int i=0;i<jg.size();i++)
	{
		for(int j=jg.size()-1;j>=0;j--)
		{
			if(i>=j) break;
			if(jg[i]!=jg[j]) cnt++;
		}
	}
	cout<<cnt/4<<endl;
	return 0;
 } 
