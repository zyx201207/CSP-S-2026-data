#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static inline ll read(){
	ll res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}

static inline void write(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=5e5+5;
int n,tail;
ll m,a[N],c[N],k=0;
queue<int> q;
int ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) c[i]=a[i]-a[i-1];
	
	for(int i=1;i<=n;++i){
		while(!q.empty()&&k+c[i]*q.size()>m) k-=a[tail]-a[q.front()],q.pop();
		k+=c[i]*q.size();q.push(i);tail=i;
		ans=max(ans,(int)q.size());
	}
	
	write(ans);putchar('\n');
	
	return 0;
}