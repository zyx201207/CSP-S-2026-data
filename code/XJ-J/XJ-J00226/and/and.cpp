#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,maxn=0;
long long a[10000000];
     
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
	if(a[i]and m)
	ans=a[i]and m;
	if(ans>maxn)
	{
	maxn+=ans;
	}else
	continue;
	}
	cout<<maxn;
	return 0;
}    
