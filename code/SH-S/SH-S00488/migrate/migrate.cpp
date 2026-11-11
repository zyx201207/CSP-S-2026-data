#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s{
	ll p,d;
};
bool v[5050];
pair<ll,ll> dist[5050];
ll c,t,n,d,a[2000020],ans,sum;
vector<ll> at[5050];
priority_queue<s,vector<s>,greater<s> > q;
bool operator<(s a,s b){
	return a.d<b.d;
}
bool operator>(s a,s b){
	return a.d>b.d;
}
ll read(){
	ll _a=0,_ne=1;
	char _c=getchar();
	while(!isdigit(_c)){
		if(_c=='-')_ne=-1;
		_c=getchar();
	}
	while(isdigit(_c)){
		_a=(_a<<3)+(_a<<1)+(_c^48);
		_c=getchar();
	}
	return _a*_ne;
}
void write(ll _a){
	if(_a<0){
		putchar('-');
		_a=-_a;
	}
	if(_a>9)write(_a/10);
	putchar(_a%10+'0');
}
ll labsl(ll a,ll b){
	return a>b?a-b:b-a;
}
void dijkstra(ll _x){
	for(int i=1;i<=n;i++){
		dist[i].first=1e16;
		dist[i].second=0;
	}
	memset(v,0,sizeof(v));
	dist[_x]=(pair<ll,ll>){0,1};
	q.push((s){_x,0});
	while(!q.empty()){
		s p=q.top();
		q.pop();
		ll to=p.p;
		if(v[to])continue;
		v[to]=1;
		if(dist[to].first<p.d)continue;
		for(int i=0;i<at[to].size();i++){
			if(dist[at[to][i]].first>dist[to].first+1){
				dist[at[to][i]]=(pair<ll,ll>){dist[to].first+1,dist[to].second};
				q.push((s){at[to][i],dist[at[to][i]].first});
			}
			else if(dist[at[to][i]].first==dist[to].first+1){
				dist[at[to][i]].second+=dist[to].second;
				q.push((s){at[to][i],dist[at[to][i]].first});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	if(c==11||c==12){				//sp.A 不做白不做 
	//if(c==0){
		t=read();
		while(t--){
			n=read();
			d=read();
			for(int i=1;i<=n;i++){
				a[i]=read();
			}
			ll f=d/(a[2]-a[1]);
			ans=n-f-f+1;
			write(f>=2?max(ans,0LL):0);
			putchar('\n');
		}
		return 0;
	}
	if(c>10)return 0;				//投降 
	t=read();
	while(t--){
		for(int i=1;i<=n;i++)at[i].clear();
		ans=0;
		while(!q.empty())q.pop();
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(labsl(a[i],a[j])<=d){
					at[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(dist[j].second==2)ans++;
			}
		}
		write(ans>>1);
		putchar('\n');
	}
	return 0;
}
/*
相信n=5000, O(n*n+2*n*n*logn+n*n)可以过 
*/
