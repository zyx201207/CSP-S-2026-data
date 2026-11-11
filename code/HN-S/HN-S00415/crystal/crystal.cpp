#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	long long a,b,sum=0;
	cin >>a>>b;
	long long num1[a+5]={0};
	for (long long i=1;i<=a;i++)
	{
		cin >>num1[i];
	}
	sort(num1+1,num1+a+1);
	int num2[100005]={0},qianzui1=0-num1[1];
	for (long long i=1;i<=a;i++)
	{
		num1[i]+=qianzui1;
	}
	for (long long i=1;i<=a;i++)
	{
		num2[num1[i]]++;
	}
	long long maxn=-1,maxi;
	for (long long i=1;i<=a;i++)
	{
		if (maxn<num2[i])
		{
			maxn=num2[i];
			maxi=i;
		}
	}
	long long qianzui2=0-maxn;
	for (long long i=1;i<=a;i++)
	{
		num1[i]-=qianzui2;
	}
	sum=num2[maxi];
	maxi-=qianzui2;
	for (long long i=maxi;i>=1;i--)
	{
		if (b-num1[i]>=0)
		{
			sum++;
			b-=num1[i];
		}
	}
	cout <<sum;
	return 0;
}
