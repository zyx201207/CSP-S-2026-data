#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum;
struct student{
	int sum;
	char name;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sum>>a[i].name;
	}
	int l1=1,r1=n,l2=1,r2=a[n].sum;
	while(l1<r1)
	{
		if(a[l1].name!=a[r1].name)
		{
			if(a[l1].sum-l2+1!=r2)
			{
				int cnt=min(a[l1].sum-l2+1,r2);
				sum+=cnt;
				l2+=cnt;
				r2-=cnt;
			}
			else
			{
				sum+=a[l1].sum;
				l1++;
				r1--;
			}
		}
		else
		{
			int cnt=min(a[l1].sum-l2+1,r2);
			l2+=cnt;
			r2-=cnt;
		}
		while(l2>a[l1].sum)
		{
			l2-=a[l1].sum;
			l1++;
		}
		while(r2<1)
		{
			r1--;
			r2+=a[r1].sum;
		}
	}
	cout<<sum;
	return 0;
} 
