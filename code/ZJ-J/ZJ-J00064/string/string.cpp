#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct node
{
	ll len;
	char x;
}a[N];
ll n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].len>>a[i].x;
	for(ll i=1,j=n; i<=j; )
	{
		if(a[i].x!=a[j].x) 
		{
			if(a[i].len<a[j].len){
				ans+=a[i].len;
				a[j].len-=a[i].len;
				i++;
			}
			else if(a[i].len==a[j].len){
				ans+=a[i].len;
				i++,j--;
			}
			else if(a[i].len>a[j].len)
			{
				ans+=a[j].len;
				a[i].len-=a[j].len;
				j--;
			}
		}
		else
		{
			if(a[i].len<a[j].len){
				a[j].len-=a[i].len;
				i++;
			}
			else if(a[i].len == a[j].len){
				i++,j--;
			}
			else if(a[i].len>a[j].len){
				a[i].len-=a[j].len;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
