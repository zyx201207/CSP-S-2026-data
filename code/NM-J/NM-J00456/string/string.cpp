#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
long long n;
long long x,sum;
char a[N],s1[N];
bool check(long long g)
     {
     	long long l1=sum;
     	for(long long j=l1;j>=1;j--)
     	    {
     	    	s1[j]=s1[l1-j+1];
     	    	long long cnt=0; 
	            for(long long i=1;i<=sum;i++)
	                if(s1[i]==s1[sum+1-i]) cnt++;
	            if(cnt==l1) return true;
			 }
		return false;
	 }
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) 
	    {
	        cin>>x;
			cin>>a[i];
	    	for(long long j=sum+1;j<=sum+x;j++)
				{
				s1[j]=a[i];
				}
			sum+=x;	
		}
	long long cnt=0; 
	for(long long i=1;i<=sum;i++)
	    if(s1[i]==s1[sum+1-i]) cnt++;
	if(cnt==sum) {cout<<0;return 0;}
	long long l=1,r=sum;
	while(l<=r)
	     {
	     	long long mid=(l+r)/2;
	     	if(check(mid)==true) r=mid-1;
	     	    else l=mid+1;
		  } 
	cout<<l+1;
	return 0;
 } 
