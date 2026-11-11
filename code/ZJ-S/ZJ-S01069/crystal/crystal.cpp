#include<bits/stdc++.h>
using namespace std;
long long n,m,s,c;
long long a[2000005],b[2000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]==a[i];
	}
	sort(a,a+1+n);
	sort(b,b+1+n);
	for(long long  i=2;i<=m;i++){
		for(long long  j=i+1;j<=m;j++){
			long long  count=0;
			count=b[j]-a[i]-a[i-1];
			if(count=m)
			{
				
				 s=i;
				 c=j;
				 
				break;
			}
		}
	}
	long long  ans=0;
	for(int i=1;i<=c;i++)
	{
		ans++;
	}
	if(ans=m)
		cout<<ans/2+1;
	else
		cout<<ans;
} 
