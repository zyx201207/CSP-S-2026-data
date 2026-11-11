#include <iostream> 
using namespace std;
int a[300005];
int num[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag[300005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	 for(int i=1;i<=n;i++)
	 {
	 	for(int j=i;j<=n;j++)
	 	{
	 		if(a[i]==false)
	 		{
	 			for(int k=1;k<=i-1;k++)
				{
					a[k]=true;
				 	a[k]==0;
				}	
			}
	 		else{
	 			flag[a[i]]=false;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]==false)
			{
				num[j]++;
			}
		}
	 }
	 for(int i=1;i<=n;i++)
	 {
	 	cout<<num[j];
	 }
	 return 0;
 } 
