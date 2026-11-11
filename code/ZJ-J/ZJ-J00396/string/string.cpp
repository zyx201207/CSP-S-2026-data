#include<bits/stdc++.h>
using namespace std;
const long long mx=2e5+10;
long long n;
long long a[mx];
char c[mx];
struct node
{
	long long num;
	char c;
};
node st1[mx*2],st2[mx*2];
long long tot1,tot2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long cnt=0;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(!flag && a[i]+cnt>(sum>>1))
		{
			flag=true;
			st1[++tot1]={(sum>>1)-cnt,c[i]};
			if(sum&1) st2[++tot2]={a[i]+cnt-(sum>>1)-1,c[i]};
			else st2[++tot2]={a[i]+cnt-(sum>>1),c[i]};
			cnt+=a[i];
		}
		else
		{
			if(!flag) st1[++tot1]={a[i],c[i]};
			else st2[++tot2]={a[i],c[i]};
			cnt+=a[i];
		}
	}
	long long ans=0;
	long long tot3=1;
	while(tot1>0 && tot3<=tot2)
	{
		long long pos=min(st1[tot1].num,st2[tot3].num);
		if(st1[tot1].c!=st2[tot3].c) ans+=pos;
		st1[tot1].num-=pos;
		st2[tot3].num-=pos;
		if(st1[tot1].num<=0) tot1--;
		if(st2[tot3].num<=0) tot3++;
	}
	printf("%lld",ans);
	return 0;
}