#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn;

bool cmp(int x,int y)
{
	return x>y;
}
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	
	for(long long i=1;i<n;i++)
	{
		long long hj=1;
		long long ms=m;
		for(long long j=i+1;j<=n;j++){
			if(a[i]-a[j]<=ms)
			{
				ms-= (a[i]-a[j]);
				hj++;
				//cout<<ms<<" "<<hj<<endl;
			}
			else break;
		}
		maxn=max(maxn,hj);
		if(maxn>n-i)break;
		//cout<<endl;
	}
 
	
	cout<<maxn;
	
	return 0;
}
	
/*/
5 5
1 2 4 8 9
9 8 4 2 1
1 1 2 1 


/*/	
	
	
	






