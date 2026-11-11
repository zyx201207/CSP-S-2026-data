#include<bits/stdc++.h>
using namespace std;
long long a;
long long n;
char c;
char b[2000000]={};
bool hw(){
	long long i = 1;j = d;
	for(;i <= d;j >= d;j++)
	{
		if(b[i] !=b[j])
		{
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{	
		cin >> a >>c;
		for(long long j = 1;j <=a;j++)
		{
			b[j] = c;
		}
	}
	int l =strlen(b)
	{
		if(hw(1))
		{
			cout << 0;
		}
	}
	long long h = 1/2;
	char yb[1000000000]={};
	for(int i = 1;i <=h;i++)
	{
		yb[i] =b[i];
	}
	long long cte = 0;
	for(long long i = l-h,j =h;i <= l,j <= h,i++,j--)
	{
		if(b[i] !=yb[j])
		{
			cte++;
		}
	}
	cout << cte;
	return 0;
	}
}

