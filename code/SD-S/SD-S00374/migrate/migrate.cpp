#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll c,t,n,d,x[N],dfn[15],sumn[N],dx,anx,a[N],sux;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(ll dep,ll lx,ll rx){
	ll op=0;
	if(dep==rx-lx+2){
		ll last=lx;bool flag=true;
		for(ll gh=lx;gh<=rx;gh++){
			if(a[dep+gh-1]){
				if(x[gh]-x[last]>d){
					flag=false;
					break;
				}
				last=gh;
				op++;
			}
		}
		if(flag&&op==sux)
			anx++;
		return ;
	}
	if(dep==1||dep==rx-lx+1){
		a[dep]=1;
		dfs(dep+1,lx,rx);
	}
	else{
		a[dep]=1;
		dfs(dep+1,lx,rx);
		a[dep]=0;
		dfs(dep+1,lx,rx); 
	}
}
bool check(ll lx,ll rx){
	anx=0;
	/*for(ll i=((1<<(rx-lx))+1);i<(1<<(rx-lx+1));i++){
		bool flag=true;
		ll last=lx;
		for(ll op=lx,gh=1;gh<=(rx-lx+1),op<=rx;op++,gh++){
			if((i>>(rx-lx+1-(gh-1)))&1){
				if(x[op]-x[last]>d){
					flag=false;
					break;
				}
				last=op;
			}
		}
		if(flag)
			anx++;
	}*/
	sux=1;
	ll lax=lx;
	for(ll jk=lx;jk<=rx;jk++){
		if(x[jk]-x[lax]<=d)
			continue;
		else{
			sux++;
			lax=jk;
		}
	}
	dfs(1,lx,rx);
	if(anx==2)
		return true;
	else
		return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(ll i=1;i<=n;i++)
			x[i]=read();
		if(c==1||c==2){
			dx++;
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					if(check(i,j))
						sumn[dx]++;
				}
			}
		}
		else{
			sumn[++dx]=n-1-d;
		}
	}
	for(ll i=1;i<=dx;i++){
		cout<<sumn[i]<<"\n";
	}
	return 0;
}
