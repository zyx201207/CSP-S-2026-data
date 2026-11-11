#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char ch[200005];
	long long nm[200005];
	long long n;
	long long ans=0;//答案 
	scanf("%lld",&n);
	long long l=0,r=n-1;//左右同时查找 
	long long i=0;
	for(long long i=0;i<n;i++){
		scanf("%lld%s",&nm[i],&ch[i]);
	}
	while(l<r)
	{
		if(ch[r]!=ch[l])
		{
			if(nm[r]==nm[l])
			{
				ans+=nm[r];
				l++;
				r--;
			}
			else if(nm[r]>nm[l])
			{
				nm[r]-=nm[l];
				ans+=nm[l];
				l++;
			}
			else
			{
				nm[l]-=nm[r];
				ans+=nm[r];
				r--;
			}
		}
		else
		{
			if(nm[r]==nm[l])
			{
				l++;
				r--;
			}
			else if(nm[r]>nm[l])
			{
				nm[r]-=nm[l];
				l++;
			}
			else
			{
				nm[l]-=nm[r];
				r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
