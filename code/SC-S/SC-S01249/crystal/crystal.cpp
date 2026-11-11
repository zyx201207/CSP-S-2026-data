#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll in(){
	ll x=0,t=1;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')t=-t;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*t;
}
inline void out(ll x){
	if(x<0)putchar('-'),x=-x;
	char stk[30];ll top=0;
	do{stk[++top]=(x%10)^48;x/=10;}while(x>0);
	while(top)putchar(stk[top--]);
}
const ll zj=5e5+10;

ll n,m,ans=1,now,a[zj],nxt;
deque<ll> q;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in(),m=in();
	for(ll i=1;i<=n;++i) a[i]=in();
	sort(a+1,a+1+n);
	q.push_back(a[1]),now=1,nxt=a[1];
	for(ll i=2;i<=n;++i){
		while(q.size()&&(a[i]-nxt)*now>m){
			m+=nxt-q.front();
			q.pop_front();
			--now;
		}
		m=m-((a[i]-nxt)*now);
		q.push_back(a[i]);
		nxt=a[i];
		++now;
		if(ans<now)ans=now;
	}
	out(ans);	
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4
*/