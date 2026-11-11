#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
int n,k,a[N]={0},cha[N],cnt=1,ans=0,ap_num=0;
bool ap=false;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=n;i++) cha[i]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int last;
	for(int i=1;i<=n;i++)
	{
		cha[i]=abs(a[i]-a[i-1]);
		/*
		if(cha[i]=last) ap_num++;
		last=cha[i];
		*/
	}
	/*
	if(ap_num==n-1) ap=true;
	
	if(ap)
	{
		while(k>=0)
	    {
		  k-=(cha[cnt+1])*cnt;
		  if(k<0) break;
		  cnt++;
	    }
	   printf("%d\n",cnt);
	   return 0;
	}
	
	else
	*/
	  for(int i=1;i<=n;i++)
      {
	      int pos=i,temp=k;cnt=1;
	      while(temp>=0)
	      {
		      temp-=(cha[pos+1])*pos;
		      if((temp<0)|| pos>n || (temp<=0 && k==0)) break;
		      cnt++;pos++;
	      }
	      ans=max(ans,cnt);
      }
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
