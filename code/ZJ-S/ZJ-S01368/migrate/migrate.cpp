#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
	ll x,s;
};
ll c,t,n,d,x[2000010],ans;
vector<ll> a[2000010];
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
bool bfs(ll x,ll y){
	queue<p> q;
	q.push({x,0});
	ll s=0,dis=0;
	while(!q.empty()){
		p tmp=q.front();
		q.pop();
//		cout<<tmp.x<<" "<<tmp.s<<"\n";
		if(tmp.x==y){
			if(!dis) dis=tmp.s;
			if(tmp.s!=dis) continue;
//			if(s>1&&tmp.s!=dis) break;
			s++;
			if(s>2) return 0;
			continue;
		}
		for(ll i=0;i<a[tmp.x].size();i++){
			ll v=a[tmp.x][i];
			if(v>y) continue;
			q.push({v,tmp.s+1});
		}
	}
//	cout<<x<<" "<<y<<" "<<s<<"\n";
	if(s==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
//		if(n<=5000){
			for(ll i=1;i<=n;i++) a[i].clear();
			ans=0;
			for(ll i=1;i<=n;i++){
				x[i]=read();
				for(ll j=1;j<i;j++){
					if(x[i]-x[j]<=d){
//						a[i].push_back(j);
						a[j].push_back(i);
					}
				}
			}
			for(ll i=1;i<=n;i++){
				for(ll j=i+1;j<=n;j++){
					if(bfs(i,j)) ans++;
//					cout<<i<<" "<<j<<"\n";
				}
			}
			printf("%lld\n",ans);
//		}
	}
}
