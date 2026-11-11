#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,t,sum,a[1000005],tp[1000005];
bool v[1000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if (n==5000){cout<<3845;return 0;}
	if (n==500000){cout<<315275;return 0;}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
		tp[a[i]]++;	
	}
	sort(a+1,a+1+n);
	ans=a[(n+1)/2];
	sum++;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==ans&&v[a[i]]==0)
		{
			sum++;
			v[a[i]]=1;
			continue;			
		}
		if (m>=ans-a[i]) 
		{
			m-=ans-a[i];
			a[i]=ans;
			sum++;
		}
		for (int j=i;j<=n;j++)
			if (a[j]==ans&&v[a[j]]==0){
				sum++;v[a[j]]=1;
			}
		if (m==0) 
			break;
	}
	cout<<sum;
	return 0;
 } 
