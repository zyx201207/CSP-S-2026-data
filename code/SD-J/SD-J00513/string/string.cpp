#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int n,a[200005];
 	char c[200005];
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		cin>>c[i];
	}
	bool b=1;
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			b=0;
		}
	}
	if(b=1)
	cout<<0;
    return 0;  	
} 
