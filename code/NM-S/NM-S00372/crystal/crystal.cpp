#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=1,a[1000000];
int main()
{
	frenopen("crystal.in","r",stdin);
	frenout("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(m==0){
			if(a[i]==a[i+1])
				sum++;	
			}
			cout<<sum;return 0;
		if(n==1){
			cout<<sum;
		}
	return 0;
}
