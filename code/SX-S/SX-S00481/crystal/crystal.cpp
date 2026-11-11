#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//Turn "long long" into "ll"
const ll N=5e5+10;//Declare the const N
int a[N];
long long s[N];//This step is the most important!
ll n,m;
void write(ll x)//Fast out function
{
	if(x<0)
	{
		x=abs(x);
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool check(ll mid)//Check binary_answer's mid
{
	for(ll l=1;l<=n-mid+1;l++)//l is 1~n-mid+1,  r is l+mid+1,  l,r's size is mid
	{
		ll r=l+mid-1;
		ll val=a[r]*mid-(s[r]-s[l-1]);
		if(val<=m) return 1;//If the value is true,return 1,else return 0
	}
	return 0;
}
int main()
{
	//The 31st and the 32nd lines can't be commented
	freopen("crystal.in","r",stdin);//see the 30th line
	freopen("crystal.out","w",stdout);//see the 30th line
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);//make them You3 Xu4 De5(I don't know its English)
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];//Qian2 Zhui4 He2(I don't know its English)
	}
	ll low=1,high=n,ans=0;
	while(low<=high)//Binary_answer
	{
		ll mid=(low+high)/2;//solve mid
		if(check(mid))
		{
			ans=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	write(ans);
	return 0;
}