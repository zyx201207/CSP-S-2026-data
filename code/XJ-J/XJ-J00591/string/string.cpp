#include<bits/stdc++.h>
using namespace std;
long long int a[200005],flag[200005]={0};
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int l,sum,n,f,maxs;
    char lz;
    cin>>n;
    cin>>a[1]>>c[1];
    lz=c[1];
    maxs=a[1];
    f=0;
    for(int i=2;i<=n;i++)
    {
    	cin>>a[i]>>c[i];
    	flag[a[i]]++;
    	maxs=max(maxs,a[i]);
    	if(c[i]!=lz)
    	{
    		f=1;
		}
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	sum=0;
	for(int i=1;i<=maxs;i++)
	{
		sum=sum+(flag[i]*i+1)/2;
	}
	cout<<sum;
	return 0;
}