#include<bits/stdc++.h> 
using namespace std;
long long a[2000000000000005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
    cin>>n>>m;
  
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
	
    long long sum=a[n];
    
    
	for(long long i=n-1;i>n-m;i--)
	{
		
	    sum=sum&a[i];
	 
	}
	
	cout<<sum;
	
	
	
	return 0;
}
