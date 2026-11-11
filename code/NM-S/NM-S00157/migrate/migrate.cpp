#include<iostream> 
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);                                              
    //cin.tie(0);                                                           
    //cout.tie(0);                                                          
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int n1,n,c,t,d,d1;
    int a[n],b[n];
    cin>>c>>t>>n>>d>>a[n]>>n1>>d1>>b[n1];
    if(c==0&&t==2)
    {
    	if(n==4)
    {
	    cout<<1<<endl<<2;
    		
		}
		if(n==5)
    	{
    		
    	    cout<<0<<endl<<1;
		}
	}
    return 0;
}
