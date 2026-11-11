#include<bits/stdc++.h>
using namespace std;
const int N=2e5+15;
#define ll unsigned long long
int n;
struct node{
	ll l,r;
	char x;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll l=1,r=0;
	for(int i=1;i<=n;i++){
		int cnt;
		cin>>cnt>>a[i].x;
		a[i].l=r+1,a[i].r=r+cnt;
		r+=cnt;
	}
	int i=1,j=n;
	ll ans=0;
	while(i<j&&l<r)
	{
		if(a[i].x==a[j].x)
		{
			ll len=min(a[i].r-l,r-a[j].l);
			if(a[i].r-l<r-a[j].l)
			{
				i++;
			}
			else
			{
				if(a[i].r-l>r-a[j].l)
				{
					j--;
				}
				else
				{
					i++,j--;
				}
			}
			
			
			l=l+len+1;
			r=r-len-1;
		}
		else
		{
			ll len=min(a[i].r-l,r-a[j].l);
			if(a[i].r-l<r-a[j].l)
			{
				ans+=a[i].r-l+1; 
				i++;
				
			}
			else
			{
				if(a[i].r-l>r-a[j].l)
				{
					ans+=r-a[j].l+1;
					j--;
					
				}
				else
				{
					ans+=r-a[j].l+1;
					i++,j--;
					
				}
			}
			
			
			l=l+len+1;
			r=r-len-1;
			//cout<<l<<" "<<r<<" "<<ans<<endl;
		}
	 } 
	 cout<<ans;
 } 
/*
6
1 a
2 b
3 c
2 a
2 b
3 a

*/
