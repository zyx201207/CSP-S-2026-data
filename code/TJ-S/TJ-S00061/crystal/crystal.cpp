#include<bits/stdc++.h>
using namespace std;
int n,br;
long long m,a[500005],s[500005],ans,dp[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]-a[i-1];
	if(n!=1)
	{
		dp[1]=0;
		for(int i=1;i<=n;i++)
	    {
		    if(i!=1) dp[i]=dp[i-1]+s[i+ans-1]-s[i];
			if(i!=1&&dp[i]>=0) break;
			else if(br-dp[i]<s[i+ans]*ans) break;
			long long r=m;
		    long long L=i,R=i;
		    long long cL=s[i],cR=s[i+1];
		    long long len=1;

		    for(int j=1;j<=n-1;j++)
		    {
			    if(cL>r&&cR>r) break;
			    else if((L==1&&cR>r)||(R==n&&cL>r)) break;
			    if(((cL<=cR&&cL<=r)||(R==n))&&L>1)
			    {
			    	r-=cL;
				    len++;
				    L--;
					cL=len*s[L];
					cR=len*s[R+1];
				}
				else 
				{
				    r-=cR;
				    len++;
				    R++;
				    cL=len*s[L];
					cR=len*s[R+1];	
				}
		    }
		    br=r;
			ans=max(ans,len);
	    }
	}
	else ans=1;
	cout<<ans;
	return 0;
}
