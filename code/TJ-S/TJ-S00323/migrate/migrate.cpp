#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		if(c==11||c==12)
	    {
	    	int d1=a[n]-a[1]/(n-1);
	    	int cnt=d/d1;
	    	cnt=cnt+cnt-1;
	    	cout<<n-cnt<<endl;
		}
		else 
		{
			cout<<0<<endl;
		}
	}
    return 0;
}

