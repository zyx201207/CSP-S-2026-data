#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int s;
	char x;
	
}a[200010];;
long  long ans=0;
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].x;
	}
	int i=1;
	int sl=0;
	int sr=0;
	int j=n;
	char lstx1,lsttx2;
	while(i<j)
	{
		if(a[i].x!=a[j].x)
		{
			
			if(sl>sr)
			{
				ans+=(sl-sr);
				a[j].s-=(sl-sr);
				sr=sl;
			}else if(sr>sl)
			{
				ans+=(sr-sl);
				a[i].s-=(sr-sl);
				sl=sr;
			}
			if(a[i].s==0)
			{
				i++;
			}
			if(a[j].s==0)
			{
				j--;
			}
			if(a[i].s>a[j].s)
			{
				ans+=a[j].s;
				a[i].s-=a[j].s;
				j--;
			}else if(a[i].s<a[j].s) {
				ans+=a[i].s;
				a[j].s-=a[i].s;
				i++;
			}else {
			ans+=a[i].s;	
			i++,j--;
			} 
		}else {
			if(sl>sr)
			{

				a[j].s-=(sl-sr);
				sr=sl;
			}else if(sr>sl)
			{

				a[i].s-=(sr-sl);
				sl=sr;
			}
			if(a[i].s>a[j].s)
			{
				a[i].s-=a[j].s;
				j--;
			}else if(a[i].s<a[j].s) {
				a[j].s-=a[i].s;
				i++;
			}else i++,j--;
		}
	}
	cout<<ans;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 } 
 /*
3
1 a
4 b
4 a
 */
