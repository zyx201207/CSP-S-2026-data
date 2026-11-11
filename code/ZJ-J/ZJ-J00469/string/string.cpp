#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,lsiz=a[1],r=n,rsiz=a[n];
	long long cnt=0;
	while(l<r)
	{
		if(lsiz>rsiz)
		{
			if(c[l]!=c[r])
			{
				cnt+=rsiz;
			}
			lsiz-=rsiz;
			r--;
			rsiz=a[r];
		}else if(lsiz<rsiz){
			if(c[l]!=c[r])
			{
				cnt+=lsiz;
			}
			rsiz-=lsiz;
			l++;
			lsiz=a[l];
		}else{
			if(c[l]!=c[r])
			{
				cnt+=lsiz;
			}
			l++,r--;
			lsiz=a[l];
			rsiz=a[r];
		}
	}
	cout<<cnt;
	return 0;
}
