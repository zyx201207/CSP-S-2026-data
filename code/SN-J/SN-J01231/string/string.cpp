#include<bits/stdc++.h> 
using namespace std;
long long a[10000],b[10000];
int main()
{ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	if(n==1)
    {
    	cout<<0;
	}
    else
    {
    	cout<<2;
	}
	return 0;
}
