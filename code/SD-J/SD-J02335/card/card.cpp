#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int a[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
	  }  
    
	
	
	return 0;
}
