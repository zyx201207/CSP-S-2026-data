/*
14:07 hi.@[tzhengqing](/user/1058570) here.

well well, so many things happened these days.
(such as got banned in florr.io?)

CSP 2023 5+85
CSP 2024 320+180
NOIP 2024 204
CSP 2025 214
NOIP 2025 124

what will go on next?

to be honest there's no reason to learn OI anymore, but I still go on.

that's the charm.

all in all,welcome to join qaswed12 OI Round 2.(oh no i forgot the link, maybe 361669? seems to be not lol)

coffee tastes good.

(try to find the wrong usage of the grammar! quite funny)

I guess emojis are ok. but there is 1% chance I got 0pts, that's bad.

maybe I shouldn't be here, cuz I forgot most of the lyrics. oh no.

---

I used 11min to print the text upside. Coding time now.

CSP-S 2026 AK +++!

---

14:23 oh no, coffee tastes too good that I'm going to drink all of it. too bad zzz  
what's the password in CSP-S? I think "Trick||Treat!" is great.

realized that I'm alive. now let this be T1 code.

deleted the emoji. guess what it is!

14:30 not providing password now?!  
that's quite bad.

someone powered off his computer, pro.

all 1024 mib.

14:33 holy craft. Greedy time!

考虑到最后的能量值必然是一个已经出现的数，不妨考虑枚举，由于权值全为 1 可以直接 Greedy，双指针维护即可。
 
14:39 lmfao accepted.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005,p=998244353,inf=100000000010299ll;
int qpow(int a,int b){int x=1,y=a;while(b){if(b&1)x=x*y%p;y=y*y%p;b>>=1;}return x;}
int n,m,a[N];
void sol()
	{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0,ans=0;
	for(int i=1;i<=n;i++)
		{
		if(a[i]!=a[i-1])sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){sum-=a[i]-a[l];l++;}
		ans=max(ans,i-l+1);
		}
	cout<<ans;
	return;
	}
signed main()
	{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;while(t--)sol();
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//Need space here.
