#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
ll n,cnt,a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	ll l=1,r=n,ans1=a[1],ans2=a[n];
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			if(ans1>ans2)
				cnt+=ans2,ans1-=ans2,ans2=0;
			else
				cnt+=ans1,ans2-=ans1,ans1=0;
		}
		else
		{
			if(ans1>ans2)
				ans1-=ans2,ans2=0;
			else
				ans2-=ans1,ans1=0;
		}
		if(!ans1)
			ans1+=a[++l];
		if(!ans2)
			ans2+=a[--r];
	}
	cout<<cnt;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
