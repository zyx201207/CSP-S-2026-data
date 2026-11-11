#include<bits/stdc++.h>
using namespace std;
long long n,dep=0,cnt=0;
long long x,l,r;
char c;
char ok[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%c",&x,&c);
		for(long long j=1;j<=x;j++)
		{
			ok[dep++]=c;
		}
	}
	if(dep%2==0){
	 	l=dep/2-1,r=dep/2;
	}
	else
	{
		l=dep/2-1,r=dep/2+1;
	}
	for(;;)
	{
	 		if(l>=0&&r<=dep-1)
	 		{
	 			if(ok[l]==ok[r])
	 			{
	 				
				 }
				 else
				 {
				 	cnt++;
				 }
				 l--,r++;
			 }
			 else
			 {
			 	break;
			 }
	}
	scanf("%d",cnt);
	return 0;
}
