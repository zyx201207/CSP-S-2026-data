#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long a[2100000],b[2100000],c[2100000];
int n,m,maxn=0;
void print()
{
	int i,sum=c[1];
	for(i=2;i<=m;i++)
	  sum=(sum&c[i]);
	maxn=max(maxn,sum);
}
void d(int t,long long sum)
{
	long long i,nx=sum;
	for(i=1;i<=n;i++)
	  if(!b[i])
	  {
	  	b[i]=1;
	  	c[t]=a[i];
	  	if(t==m) 
	  	  print();
	  	else
	  	  d(t+1,nx);
	  	b[i]=0;
	  }
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
      cin>>a[i];
    d(1,1);
    cout<<maxn;
	return 0;
}

