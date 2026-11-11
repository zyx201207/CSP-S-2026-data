#include<bits/stdc++.h>
using namespace std;
long long n,m,f,sum,bzx,ck;
long long a[200005];
long long er[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long cnt[31];
void cer(long long f)
{
	for(int i=0;i<=30;i++)
	{
		if(er[i]>f) break;
		cnt[i]+=bool((f&er[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool pd=true;
	ck=30;
	while(pd)
	{
//		cout<<endl;
//		cout<<ck<<' '<<bzx<<' '<<sum<<endl;
		if(bzx==1||ck<0) break;
		for(int i=1;i<=n;i++)
		{
//			cout<<a[i]<<' ';
			cer(a[i]);
		}
//		cout<<endl;
		int js=m;
		pd=false;
		/*for(int i=0;i<=ck;i++)
		{
			cout<<cnt[i]<<' ';
		}
		cout<<endl;*/
		for(int i=ck;i>=0;i--)
		{
			if(cnt[i]>=m)
			{	
				sum+=er[i];
				bzx=er[i];
				ck=i-1;
				pd=true;
				break;
			}
		}
		for(int i=0;i<=ck;i++) cnt[i]=0;
		int fcnt=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>bzx) a[fcnt++]=a[i];
		}
		n=fcnt-1;
	}
	cout<<sum;
	/*
	for(int i=0;i<=30;i++)
	{
		cout<<cnt[i]<<' ';
	}
	cout<<endl;*//*
	for(int i=30;i>=0;i--)
	{
		if(js==0) break;
		if(cnt[i]>=m)
		{
			js--;
			sum+=er[i];
		}
	}
	cout<<sum;*/
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long n,m,f,sum;
long long er[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long cnt[31];
void cer(long long f)
{
	for(int i=0;i<=30;i++)
	{
		if(er[i]>f) break;
		cnt[i]+=bool((f&er[i]));
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f;
		cer(f);
	}
	int js=m;
//	for(int i=0;i<=30;i++)
//	{
//		cout<<cnt[i]<<' ';
//	}
//	cout<<endl;
	for(int i=30;i>=0;i--)
	{
		if(js==0) break;
		if(cnt[i]>=m)
		{
			js--;
			sum+=er[i];
		}
	}
	cout<<sum;
	return 0;
}*/
