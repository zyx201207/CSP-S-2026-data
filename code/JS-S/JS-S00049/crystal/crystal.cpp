#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=500010;
int n,m,a[N],ans,s,mm;
priority_queue<int>q;

inline void read(int&x){
	x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f^=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x=(f?-x:x);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i)
		read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		mm-=(a[i]-a[i-1])*s;
		++s;
		q.push(-a[i]);
		while(mm<-m){
			mm+=a[i]+q.top();
			q.pop();
			--s;
		}
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}

//

/*
Just simply recalling...
Unlike last year,
there's not so much desire for the Winter Camp.
"Where should I stop?"
I asked myself.
In fact,
whatever it turns out to be,
I'll treasure it,forever.
//freopen
*/