//hezhuchen延安新区第一中学SN-J00632 
#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,num=0,maxn=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n-1;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[i] & a[j] > maxn){
				maxn=a[i] & a[j];
			}
		}
	}
	cout<<maxn;
	return 0;
}
