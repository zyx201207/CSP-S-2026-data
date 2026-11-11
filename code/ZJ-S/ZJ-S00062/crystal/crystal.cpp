#include<bits/stdc++.h>
using namespace std;
long long num[500009];
int q[500009][2];
int pre[500009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		
	int n;
	long long m,ty=0,deta;
	scanf("%d %lld",&n,&m);
	long long in;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	std::sort(&num[1],&num[n]);
	num[n+1]=1000000000009;
	long long ans=-1;
	int st=1,ct=1;
	for(int i=2;i<=n+1;i++)
	{
		if(num[i]!=num[i-1])
		{
			q[ct][0] =st;
			q[ct][1] =i-1;
			st = i;
			ct++;
		}
	}
	int x;
	deta=num[2]-num[1];
	int l=1;
	int maxnum=-1;
	for(int i=2;i<=ct;i++)
	{
		ty+=(num[q[i][1]]-num[q[i-1][1]])*(q[i-1][1]-q[l][0]+1);
		x = q[l][0];
		if(ty >m)
		{
			while(ty >m)
			{
				ty -= (num[q[i][1]]-num[q[l][1]]);
				x++;
				if(x > q[l][1])
					l++;
			}
			if(x != q[l][0]){
			ty -=(num[q[i][1]]-num[q[l][1]])*(q[l][1]-x+1);
			l++;}
			x--;
		}
		if(q[i][1] - x +1 > ans)
			ans =q[i][1] - x +1;
	}
	printf("%lld",ans);
	return 0;
}
