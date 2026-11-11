#include <bits/stdc++.h>
using namespace std;
int n,a[50005],cnt=0,b=0,cnt1=0;
long long m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)
    	{
    		if(a[j]>=a[i])cnt++;
    		if(n/2!=0)
    		{
    			if(cnt==n/2+1)break;
			}
			else 
			{
				if(cnt==n/2)
				break;
			}
    		
		}
		
	}

	for(int i=cnt;i>=1;i--){
		b+=a[cnt]-a[i];
		if(b==m)break;
	}
	for(int i=1;i<=n;i++)
	{
		b-=a[cnt]-a[i];	
		a[i]+=a[cnt]-a[i];
		if(b==0)break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[cnt])cnt1++;
	}
	cout<<cnt1;
	
	return 0;
   
}

