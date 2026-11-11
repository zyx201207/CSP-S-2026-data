#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[500005],v=1,da=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=n;i>1;i--)
	{mm=m;v=1;
		for(int j=i-1;j>=1;j--)
	    {
	    	if(mm-(a[i]-a[j])>=0) {v++;mm=mm-(a[i]-a[j]);}
	    	    else break;
		}
		da=max(da,v);
	}
	cout<<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
