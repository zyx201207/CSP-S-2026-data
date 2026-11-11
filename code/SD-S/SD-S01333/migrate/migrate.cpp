#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
void readd(T& x){
	x=0;
	int f=1;
	char c=getchar();
	while(c!='-'&&(c>'9'||c<'0')) c=getchar();
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	x*=f;
}
template<typename T>
void printt(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) printt(x/10);
	putchar(x%10+'0');
}
const int N=2e6+10;
ll x[N];
ll n,d,maxm,ans,cnt;
bool f;
void dfs(ll l,ll r,ll st){
	if(st>maxm) return ;
	if(st==maxm&&l==r){
		cnt++;
		if(cnt>2){
			f=0;
		}
		return ;
	}
	for(int i=l+1;i<=r&&f;i++){
		if(x[i]-x[l]<=d){
			dfs(i,r,st+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	readd(c);
	readd(t);
	while(t--){
		readd(n);
		readd(d);
		for(int i=1;i<=n;i++){
			readd(x[i]);
		}
		ll e,w;
		ans=0;
		for(int l=1;l<=n-2;l++){
			for(int r=l+2;r<=n;r++){
				e=l,w=l+1;
				maxm=0;
				while(w<r){ 
					if(w<r&&x[w+1]-x[w]>d) break;
					while(w<r&&x[w+1]-x[e]<=d) w++;
					maxm++;
					e=w;
				}
				//cout<<"Debug:"<<l<<' '<<r<<' '<<maxm<<'\n';
				if(maxm>1&&r-l>maxm){
					//cout<<"Debug:in"<<l<<' '<<r<<"\n\n";
					f=1;
					cnt=0;
					dfs(l,r,0);
					if(cnt==2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

