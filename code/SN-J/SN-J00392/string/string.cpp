#include<bits/stdc++.h>
#define N 200005
using namespace std;
long long n;
long long a[N];
char c[N]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	bool fl=true;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i-1>0)
		fl=false;
	}
	//cout<<fl<<'\n'; 
	if(fl)
	{
		cout<<'0';
		return 0;
	}
	long long te;
	if(n%2==0)te=n/2;
	else te=(n+1)/2;
	bool flg=true;
	for(long long i=1;i<=te;i++)
	{
	    if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1])
	    {
	    	flg=false;
	    	break;
		}
	}
	//cout<<flg<<'\n';
	if(flg)
	{
		cout<<'0';
		return 0;
	}
	long long cnt=0ll;
	for(long long i=1;i<=te;i++)
	{
		if(c[i]==c[i-1]&&a[i]!=a[n-i+1])
		{
			long long num=a[i]-a[n-i+1];
			cnt+=abs(num);
            			
		}
		else 
		{
		    if((c[i]!=c[n-i+1]&&a[i]==a[n-i+1])||(c[i]!=c[n-i+1]&&a[i]!=a[n-i+1]))
			cnt+=max(a[i],a[n-i+1]);	
		} 
		//cout<<cnt<<' ';
	}
	//cout<<'\n';
	cout<<cnt;
return 0;
}
