//陕西省西安中学 马浩涵 SN-S00348 
#include<bits/stdc++.h>
using namespace std;
const int N=500050;
long long n,m;
long long a[N]; 
long long choose=1e18;
long long b[N];
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	sort(a,a+n);
	long long chahe1=0;
	long long chahe2=0;
	long long choose=0;
	long long pos=0;
	if(n%2==0)
	{
		int mid=n/2;
		long long x=a[mid];
		long long y=a[mid+1];
		
		for(int i=0;i<n;i++)
		{
			chahe1+=abs(x-a[i]);
			chahe2+=abs(y-a[i]);
		}
		if(chahe1<chahe2)
		{
			choose=x;
			pos=mid;
		}
		else 
		{
			choose=y;
			pos=mid+1;
			
		}
	}
	else 
	{
	   int mid=n/2+1;
	   choose=a[mid];
	   pos=mid;
	}
	
	int sum=0;
	int l=0;
	for(int i=0;i<n;i++)
	{
		
		
		if(choose-a[i]==0) continue;
		
		b[l]=abs(choose-a[i]);
		l++;
		
	}
	sort(b,b+l);
    
	long long ans=0;

	long long last=m;
	long long counting=0;
	for(int i=0;i<n;i++)
    {
    	if(a[i]==choose)counting++;
	}

	for(int i=0;i<l;i++)
	{
		
		
		if(last-b[i]>=0)
		{
		    ans++;
		    last-=b[i];
		    
		    
		}
		
		
	}
	
	cout<<ans+counting;
	return 0;
}
