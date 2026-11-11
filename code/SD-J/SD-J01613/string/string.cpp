#include<bits/stdc++.h>
using namespace std;
long long n,sum,x[200005];
char c[200005];
int main() 
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>c[i];
	long long l=1,r=n;
	while(1)
	{
		if(l==r)break;
		if(x[l]>x[r])
		{
			if(c[l]==c[r]);
			else sum+=x[r];
			x[l]-=x[r];
			r--;
		}
		else if(x[l]<x[r])
		{
			if(c[l]==c[r]);
			else sum+=x[l];
			x[r]-=x[l];
			l++;
		}
		else if(x[l]==x[r])
		{
			if(c[l]==c[r]);
			else sum+=x[l];
			l++,r--;
			if(l>r)break;
		}
	}
	cout<<sum;
	return 0;
}
