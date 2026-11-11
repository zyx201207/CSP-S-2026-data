#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,x,y,ans;
ll w[500050];
ll k[550];
vector<ll> a[550],t[550];
vector<pair<ll,ll> > l[500050];
ll h[550][550];						//»»³Ë 
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
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i].push_back(read());
			t[i].push_back(read());
			l[a[i][j-1]].push_back((pair<ll,ll>){(ll)i,(ll)j-1LL});
		}
	}
	//return 0;			0.5s
	memset(h,0x3f,sizeof(h));
	for(int i=1;i<=n;i++){
		h[i][i]=0;
	}
	//return 0;			0.5s
	for(int k=1;k<=m;k++){
		ll _k=l[k].size();
		for(int i=0;i<_k;i++){
			for(int j=i+1;j<_k;j++){
				h[l[k][i].first][l[k][j].first]=min(
					h[l[k][i].first][l[k][j].first],
					t[l[k][i].first][l[k][i].second]+t[l[k][j].first][l[k][j].second]
				);
			}
		}
	}
	//return 0;			0.6s
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
			}
		}
	}
	//return 0;			1.1s
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			h[i][j]=min(h[i][j],h[j][i]);
			h[j][i]=min(h[j][i],h[i][j]);
		}
	}
	//return 0;
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d %d: %lld\n",i,j,h[i][j]);
		}
	}
	*/
	while(q--){
		x=read();
		y=read();
		ans=1e16;
		for(int i=0;i<l[x].size();i++){
			for(int j=0;j<l[y].size();j++){
				ans=min(ans,
				h[l[x][i].first][l[y][j].first]+
				t[l[x][i].first][l[x][i].second]+
				t[l[y][j].first][l[y][j].second]+
				w[x]+w[y]
				);
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
/*
O(m+n+K+n+m*d*d+n*n*n+n*n+q*d*d);
n 500
m 5e5
k 5e5
d 20
q 1e5
=3.6*10^8
1.25e8=0.5s
O(m*d*d+q*d*d+n*n*n);
n^3 = floyd
m*d*d = Õ¾ÄÚ»»³Ë 
q*d*d = Ñ¯ÎÊ 
*/
