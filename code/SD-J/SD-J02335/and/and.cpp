#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;


int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c=0;
    int b=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	 b=a[1];
    	
    	if(a[i]==b) c++;
    	else max(b,a[i]);
	}
	if(c==n)
	{
		cout<<b;
	}
	if(m==1)
	{
		cout<<b;
	}
	

	return 0;
}
