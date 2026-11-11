#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
long long a[N],ans,maxa;
int n,m;
bool ok;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if((a[i]+1)%2!=0)ok=true;
	}
	sort(a+1,a+1+n);
	maxa=a[n];
    if(m==1)cout<<maxa;
    else if(m==2&&n<=5000)
    {
    	for(int i=1;i<=n;i++)
    	 for(int j=1;j<=n;j++)
    	  if(j!=i)ans=max(ans,a[i]&a[j]); 
    	cout<<ans;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		ans&=a[i];
		cout<<ans;
	}
	else if(!ok)
	{
		cout<<maxa;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
