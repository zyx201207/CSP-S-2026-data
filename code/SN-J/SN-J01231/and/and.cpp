#include<bits/stdc++.h>
using namespace std;
long long mx=0,mi=100000000;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[1000];
	for(int i=0;i<n;i++)
	{
    	cin>>a[i];	
    	mx=max(a[i],mx);
    }
    for(int i=0;i<n;i++)
    {
    	mi=min(a[i],mi);
	}
	if(m==1) 
	{
		cout<<mx;
	}
    if(m==n)
	{
		cout<<mi;
	}
	else
	{
		cout<<mx-mi;
	}
}
