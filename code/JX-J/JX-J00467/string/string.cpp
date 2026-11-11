#include <bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int cntl=0;
int cntr=0;
char c[200010];
long long a[200010];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	cin>>c[i];
}
cntr=n;
cntl=1;
while(cntl<cntr)
{
	if(c[cntl]==c[cntr])
	{
		if(a[cntl]>=a[cntr])
		{
			a[cntl]-=a[cntr];
			cntr--;
		}else
		{
			a[cntr]-=a[cntl];
			cntl++;
		}
	}
	else
	{
		if(a[cntl]>=a[cntr])
		{
			a[cntl]-=a[cntr];
			ans+=a[cntr];
			cntr--;
		}else
		{
			a[cntr]-=a[cntl];
			ans+=a[cntl];
			cntl++;
			
		}
	}
}
cout<<ans;
return 0;
}
