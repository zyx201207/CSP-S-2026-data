#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],sum,ans,l,r,t;
char c[200010];
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		t+=a[i];
	}
	t=t/2;
	l=1,r=n;
	while(l<=r)
	{
		if(l==r) break;
		
		if(a[l]<a[r])
		{
			if(c[l]!=c[r])
			{
				if(t-sum<a[l]) {ans+=t-sum;break;}
				else ans+=a[l];
			}  
			sum+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				if(t-sum<a[r]) {ans+=t-sum;break;}
				else ans+=a[r];
			}
			sum+=a[r];
			a[l]-=a[r];
			r--;
		}
		else
		{
			if(c[l]!=c[r])
			{
				if(t-sum<a[r]) {ans+=t-sum;break;}
				else ans+=a[r];
			}
			sum+=a[r];
			a[l]=a[r]=0;
			l++;
			r--;
		}
	}
	cout<<ans;
}
//Trick||Treat!