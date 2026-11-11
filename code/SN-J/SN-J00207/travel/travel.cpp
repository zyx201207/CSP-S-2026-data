#include<bits/stdc++.h>
using namespace std;
bool same(string a,string b)
{
	if(a[1]==b[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool same2(string a,string b)
{
	if(a[1]==b[1])
	{
		if((a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C') || ((a[2]=='D' || a[2]=='F') && (b[2]=='D' || b[2]=='F'))) return 1;
	}
	else
	{
		return 0;
	}
}
bool same3(string a,string b)
{
	if(a[1]==b[1])
	{
		if(a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C')
		{
			if(a[2]-1==b[2] || a[2]+1==b[2]) return 1;
		}
		else if ((a[2]=='D' || a[2]=='F') && (b[2]=='D' || b[2]=='F')) return 1;
		else return 0;
	}

}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(same(s1,s2)) cout<<"1";
		else cout<<"0";
		if(same2(s1,s2)) cout<<"1";
		else cout<<"0";
		if(same3(s1,s2)) cout<<"1";
		else cout<<"0";
	 } 
	else cout<<"0000";
	
 } 
