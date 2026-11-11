#include <iostream>
using namespace std;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	char c[200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	} 
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			char c1=c[1];
		}
		else{
			if(c[i]!=c1)
			{
				bool=false;
			}
		}
	}
	if(bool==true)
	{
		cout<<"0";
	}
	return 0;
 } 
