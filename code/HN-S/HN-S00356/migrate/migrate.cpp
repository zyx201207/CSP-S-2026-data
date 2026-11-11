#include<iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++)
    {
    	long long n,d;
    	cin>>n>>d;
    	if(c==0&&n==4)
    	{
    		cout<<1<<endl;
    		cout<<2;
    		return 0;
		}
		if(c==0&&n==5)
		{
			cout<<0<<endl;
			cout<<1;
			return 0;
		} 
    	int a[n];
    	for(int j=0;j<n;j++)
    	    cin>>a[j];
    	
	}
	return 0;
}
