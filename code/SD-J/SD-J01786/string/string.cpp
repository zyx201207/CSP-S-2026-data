#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long x;
	char c;
}a[200007];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
	}
	for(long long l=1,r=n;l<=r;)
	{
		if(a[l].c!=a[r].c)
		{
			if(a[l].x>a[r].x)
			{
				ans+=a[r].x;
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}
			else if(a[l].x<a[r].x)
			{
				ans+=a[l].x;
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
			else
			{
				ans+=a[l].x;
				l++;
				r--;
				//cout<<ans<<' '<<a[l].x<<endl;
			}
		}
		else
		{
			if(a[l].x>a[r].x)
			{
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}
			else if(a[l].x<a[r].x)
			{
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
//good bye world
