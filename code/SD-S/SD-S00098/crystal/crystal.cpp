#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FOR(i,x,y) for(int i=(x);i<=(y);i++)
#define ROF(i,x,y) for(int i=(x);i>=(y);i--)
#define EDGE(i,u) for(int i=head[u];~i;i=e[i].nxt)
#define pb push_back 
#define fi first
#define se second
int read(){
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}

const int N=1e6+5;

// Oct31==Dec25?
// 20min

int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	int l=0,r=0;
	int now=0,ans=0;
	FOR(i,0,n-1){
		now+=(a[i+1]-a[i])*(i-l+1);
		while(now>m){
			now-=(a[i+1]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1+1);
	}
	print(ans);
	
	return 0;
} 
