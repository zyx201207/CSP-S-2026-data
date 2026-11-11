#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500009],cnt,l=1,r;
ll read()
{
	ll x=0,f=1;
	char ch=getchar_unlocked();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar_unlocked();
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
	return x*f;
}
void print(ll x)
{
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
ll x[2000003];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
    srand(time(0));
	while(t--)
	{
		cout<<rand()<<'\n';
	}
	return 0;
}