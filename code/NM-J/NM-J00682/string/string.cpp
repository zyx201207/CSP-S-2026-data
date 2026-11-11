#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001];
char c[200001];
long long l=1,r=n;
long long ansl,ansr,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	 cin>>a[i]>>c[i];
	 
	 ansl=a[l];
	 ansr=a[n];
	 while(l<=r)
	    {
	      if(ansl>=ansr)
	        {
	          if(c[l]!=c[r])
	             ans+=ansr;
	          r--;
	          ansl-=ansr;
	          ansr=a[r];
	          continue;
	        }
	      else
	        {
	          if(c[l]!=c[r])
	             ans+=ansl;
	          l++;
	          ansr-=ansl;
	          ansl=a[l];
	          continue;
	        }
	  }
	  cout<<ans;  
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
