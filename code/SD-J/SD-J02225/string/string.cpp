#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+10;
ll n;
ll b;
struct node{
	ll num;
	char cnt;
}a[N];
ll l,r;
ll mi;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		scanf("%lld%s",&a[i].num,&a[i].cnt);
	}
	l=1,r=n;
	while(l<r)
	{
		mi = min(a[l].num,a[r].num);
		if(a[l].cnt != a[r].cnt)
		{
			b+=mi;
		}
		a[l].num-=mi;
		a[r].num-=mi;
		if(a[l].num == 0){
			l++;
		}
		if(a[r].num == 0){
			r--;
		}
	}
	cout<<b;
}



