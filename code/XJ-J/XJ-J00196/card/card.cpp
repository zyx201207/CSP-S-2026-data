#include<iostream>
using namespace std;
int main()        
{
	frozen("card.in","r",std.in)
	frozen("card.out","w",std.out)
	int n,m;
	int a[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=a[i+1])
		{
			n=0; 
		}
	}
	
	return 0;
}
