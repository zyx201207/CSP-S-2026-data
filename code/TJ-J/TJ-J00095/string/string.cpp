#include<bits/stdc++.h>
using namespace std;
unsigned long long n,goint,sum;
string a,gostring;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>goint>>gostring;
		for(int i=1;i<=goint;i++)
		{
			a+=gostring;
		}
	}
	long long l=0,r=a.size()-1;
	while(l<=r)
	{
		
		if(a[l]!=a[r]) sum++;
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
