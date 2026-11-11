#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans=0,i,j;
int num[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>num[i]>>c[i];
	i=0,j=n-1;
	while(i<=j)
	{
		if(num[i]>num[j])
		{
			if(c[i]!=c[j]) ans+=num[j];
			num[i]-=num[j];
			j--;
		}
		else
		{
			if(c[i]!=c[j]) ans+=num[i];
			num[j]-=num[i];
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
