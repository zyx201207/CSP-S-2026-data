#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
ll read(){
	char c=getchar();
	ll l=1,ret=0;
	while(!isdigit(c))l=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*l;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e6+7;
int c,t;
ll n,D,x[N],l[N],r[N],id,ans;
vector<ll> v;
ll dis(ll a,ll b){
	v.clear();
	while(r[a]<b){
		if (r[a]==a) return -1;
		a=r[a],v.push_back(a);
	}
	ll ret=0;
	for(int i=v.size()-1;i>=0;i--){
		b=l[b];
		ret+=v[i]-b;
	}
	return ret;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();D=read();
		for(int i=1;i<=n;i++)x[i]=read();
		ans=0;
		if (n<=2){
			write(0);
			putchar('\n');
			continue;
		}
		if (c>=11&&c<=12){
			if (n>1&&x[2]-x[1]>0){
				ll num=D/(abs(x[2]-x[1]));
				ans=n-2*num+1;
				if (num>1&&ans>=0){
					write(ans);
					putchar('\n');
					continue;
				}
			}
			write(0);
			putchar('\n');
			continue;
		}
		if (c>=13&&c<=14){
			if (n<=2){
				write(0);
				putchar('\n');
				continue;
			}
			if (dis(x[1],x[n])==1) ans++;
			if (dis(x[1],x[n]-1)==1) ans++;
			if (dis(x[1]+1,x[n])==1) ans++;
			write(ans);
			putchar('\n');
			continue;
		}
		id=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[id]>D)id++;
			l[i]=id;
		}
		id=n;
		for(int i=n;i>=1;i--){
			while(x[id]-x[i]>D)id--;
			r[i]=id;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if (dis(i,j)==1) ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}