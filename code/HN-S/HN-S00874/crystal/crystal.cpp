#include <bits/stdc++.h>
using namespace std;
long long n,m,i,q,maxx=0,a[500001],b[500001];
int asd(int x)
{   int j=1,m1=m,sum=0;
	while(j<=n)
	{
		b[j]=x-a[j];
		if(b[j]<0) break;
		else j++;
	}
    for(int k=j;k>=1;k--)
    {
    	if(m1-b[k]>=0)
    	{   m1-b[k];
    		sum++;
		}
		else break;
	}
	return sum;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=asd(a[1]);
	i=2;
    while(i<=n){
    	if(a[i]!=a[i-1])
    	{   q=asd(a[i]);
    		maxx=max(maxx,q);
		}
		i++;
	}
	cout<<maxx-1;
	return 0;
}
