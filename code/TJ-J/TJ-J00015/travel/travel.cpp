#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,i,c1[10005],s1[10005],c2[10005],s2[10005];
	cin>>n>>i;
	if(c1[i]==c2[i])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c1[i]==s1[i]&&c1[i]==s2[i])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(c2[i]==s1[i]||c2[i]==s1[i])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[i]==s2[i])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
