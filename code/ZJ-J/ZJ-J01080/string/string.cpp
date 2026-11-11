#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,a[N],ans;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long i=1,j=n;
	while(i<j)
	{
		if(b[i]==b[j])
		{
			if(a[i]>a[j])a[i]-=a[j],a[j]=0,j--;
			else if(a[i]<a[j])a[j]-=a[i],a[i]=0,i++;
			else a[j]=0,a[i]=0,i++,j--;
		}
		else
		{
			if(a[i]>a[j])ans+=a[j],a[i]-=a[j],a[j]=0,j--;
			else if(a[i]<a[j])ans+=a[i],a[j]-=a[i],a[i]=0,i++;
			else ans+=a[i],a[j]=0,a[i]=0,j--,i++;
		}
	}
	cout<<ans;
	return 0;
}
