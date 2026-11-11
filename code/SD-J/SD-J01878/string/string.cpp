#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const A=2e5+5;
struct ch{
	ll a;
	char c;
};
deque<ch> dq;
int n;
ll cnt=0;
char c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		ch p;
		scanf("%lld%c%c",&p.a,&c1,&p.c);
		dq.push_back(p);
	}
	while(dq.size()>1){
		ch p1,p2;
		p1=dq.front();
		p2=dq.back();
		dq.pop_front();
		dq.pop_back();
		ll a;
		if(p1.a>p2.a){
			a=p2.a;
			if(p1.c!=p2.c) cnt+=a;
			p1.a-=a;
			dq.push_front(p1);
		}
		else if(p1.a<p2.a){
			a=p1.a;
			if(p1.c!=p2.c) cnt+=a;
			p2.a-=a;
			dq.push_back(p2);
		}
		else{
			if(p1.c!=p2.c) cnt+=p1.a;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
