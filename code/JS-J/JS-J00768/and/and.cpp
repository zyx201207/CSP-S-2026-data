#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2e5+1;
ll n,m,a[N],ans;
bool f[N];

void dfs(ll b,ll t,ll x)
{
	if(b==m+1){ans=max(ans,x);return ;}
	if(m-b-1>n-t) return ;
	for(ll i=t+1;i<=n;++i)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(b+1,i,x&a[i]);
			f[i]=0;
		}
	}
}

ll tp1()
{
	ll ans=2147483647;
	for(ll i=1;i<=n;++i)
		ans=ans&a[i];
	return ans;
}

ll tp2()
{
	ll ans=2147483647;
	for(ll i=n-m+1;i<=n;++i)
		ans=ans&a[i];
	return ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	if(m==1){printf("%lld\n",a[n]);return 0;}
	if(m==n){printf("%lld\n",tp1());return 0;}
	if(n>2000){printf("%lld\n",tp2());return 0;}
	dfs(1,0,2147483647);
	printf("%lld\n",ans);
	return 0;
}
/*
* luogu:Chu_Si(938510)
* 
* 7:57
* Let's make the diary.
* 
* 8:10
* Don't write baoli language.
* Or you will be punished for 3 years.
* 
* 8:29
* The preson who sit opposite to me said to the teacher:
* There is no coding apps.(Of course he's a Chinese,but I'm lazy)
* What are you saying?
* 
* 8:41
* T1 over
* 
* 8:53
* T2 over
* 
* 10:19
* T4 50pts,T3 40pts
* kong bei qie...
* 
* 10:42
* Maybe I can work out T3 B(14&15,10pts)?
* 
* 10:51
* Yes I can.
* Why B is similiar to A.?
* Am I wrong?I'm just access the add4.ans.
* I don't want to think more.
* 300pts max,Let me have a rest.
* (T1 100pts,T2 100pts, T3 50pts,T4 50pts)
* 
* 10:57
* Why so cold(TAT
* 
* In fact I wrote more about the 3.5h+.
* But I think some of them is useless,
* so I deleted them,and all the things above
* is the rest.
*/
