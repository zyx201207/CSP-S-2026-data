#include<bits/stdc++.h>
using namespace std;
int n;
int a[200007],sum=0;
char c[200007];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i]>>c[i];
	sum+=a[i];
}
int mid=sum/2;
int i=1;
int j=n-i+1;
int t=0;
long long ans=0;
while(mid>0)
{
//	cout<<++t<< " "<<mid<<" "<<i<<" "<<j<<endl;
int x=n-i+1;

	int diff=min({a[i],a[j],mid});
	if(a[i]>diff)
	{
		a[i]-=diff;
		if(c[i]!=c[j])
		{
			ans+=diff;
		}
		if(a[j]<=diff)
		{
			j--;
		}
		mid-=diff;
	}
	else if(a[j]>diff)
	{
		a[j]-=diff;
		if(c[i]!=c[j])
		{
			ans+=diff;
		}
		if(a[i]<=diff)
		{
			i++;
		}
		mid-=diff;
	}
	else if(a[i]==a[j])
	{	
		if(c[j]!=c[i])
		ans+=diff;
		mid-=diff;
		i++,j--;
	}
}
cout<<ans;
return 0;
}
