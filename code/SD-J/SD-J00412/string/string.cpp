#include<bits/stdc++.h>
using namespace std;

long long qj=0,hj=0;
long long n,sum=0;
long long a[200005];
char c[2000005],y;

void cl(char qc,long long qs,char hc,long long hs,long long l)//c为字符 s为长度 l为当前轮数 
{
	if(qc==hc)
	{
		if(c[l]==c[n-l+1]) 
		{
			if(qs!=hs)
			{
				if(qs>hs)
					qj=qs-hs;
				else
					hj=hs-qs;
			}
			y=qc;
		}
	}
	else
	{
		sum+=min(a[l],a[n-l+1]);
		if(qs!=hs)
		{
			if(qs>hs)
			{
				qj=qs-hs;
				y=qc;
			}
			else
			{
				hj=hs-qs;
				y=hc;
			}
		}
	}
}

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];//a是长度 c是字符 
	for(int i=1;i<=n/2;i++)
	{
		
		if(qj!=0||hj!=0)
		{
			if(qj!=0)
			{
				cl(y,qj,c[n-i+1],a[n-i+1],i);
				qj=0;
			}
			else
			{
				cl(c[i],a[i],hj,y,i);
				hj=0;
			}
		}
		else
		{
			cl(c[i],a[i],c[n-i+1],a[n-i+1],i);
		}
	}
	cout<<sum;
	return 0;
}
