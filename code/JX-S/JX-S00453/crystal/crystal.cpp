#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
sort(a+1,a+1+n);

long long r=1; 
long long l=1;
long long sum=0;
long long len=0;
long long maxx=0;
while(r<=n)
{
	if(sum+len*(a[r]-(a[r-1]))<=m)
	{
		sum=sum+len*(a[r]-(a[r-1]));
		len++;
		r++;
	}else
	{
		maxx=max(maxx,len);
		sum=sum-(a[r-1]-a[l]);
		len--;
		l++;
	}
}
cout<<maxx;
return 0;
}
