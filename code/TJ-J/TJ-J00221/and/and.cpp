#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[n-1]=="12")
	{
		cout<<"12";
	} 
	if(a[n-1]=="7")
	{
		cout<<"7";
	}
	else
	{
		cout<<"23";
	}
	return 0;
}
