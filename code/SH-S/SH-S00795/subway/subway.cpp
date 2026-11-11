#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const ll INF=5e18;

ll debug(ll x,string y){
	if(x>INF) cout<<y<<endl;
	return x;
}

ll n,m,d,q,x,y;
ll ans;
ll w[500010];
ll k[510];
ll a;
ll t;
vector<ll> att[500010];
vector<ll> b[500010];

ll ljb[510][510];
ll zdl[510][510];

ll kuaidu(){
	ll num=0;
	char neo;
	neo=getchar();
	while(neo<'0'||'9'<neo){
		neo=getchar();
	}
	while('0'<=neo&&neo<='9'){	
		num=num*10+neo-'0';
		neo=getchar();
	}
	return num;
}

void kuaixie(ll sth){
	char a[19];
	int i;
	for(i=0;i<19&&sth>0;i++){
		a[i]=sth%10+'0';
		sth/=10;
	}
	i--;
	for(i=i;i>=0;i--){
		putchar(a[i]);
	}
}

void yhljb(ll X,ll Y,ll Z){
	ljb[X][Y]=min(ljb[X][Y],Z); 
}

void yhzdl(ll X,ll Y,ll Z){
	zdl[X][Y]=min(zdl[X][Y],Z); 
}

void yhans(ll Z){
	ans=min(ans,Z); 
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	kuaidu();
	
	n=kuaidu();
	m=kuaidu();
	d=kuaidu();
	q=kuaidu();

	for(ll i=1;i<=m;i++){
		w[i]=kuaidu();
	} 
	for(ll i=1;i<=n;i++){
		k[i]=kuaidu();
		for(ll j=1;j<=k[i];j++){
			a=kuaidu();
			t=kuaidu();
			att[a].push_back(i);
			b[a].push_back(t);
		}
	}
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			ljb[i][j]=INF;
			zdl[i][j]=INF;
		}
	}
	
	for(ll i=1;i<=n;i++){
		zdl[i][i]=0;
		ljb[i][i]=0;
	}
	
	for(ll i=1;i<=m;i++){
		for(size_t e=0;e<att[i].size();e++){
			for(size_t f=e+1;f<att[i].size();f++){
				yhljb(att[i][e],att[i][f],b[i][e]+b[i][f]);
				yhljb(att[i][f],att[i][e],b[i][e]+b[i][f]);
			}
		}
	}
	
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			yhzdl(i,j,ljb[i][j]);
			yhzdl(j,i,ljb[i][j]);
			for(ll e=1;e<j;e++){
				yhzdl(i,e,zdl[j][e]+ljb[i][j]);
				yhzdl(e,i,zdl[e][j]+ljb[i][j]);
			}
		}
	}
	
	for(ll i=1;i<=q;i++){
		x=kuaidu();
		y=kuaidu();
		ans=INF;
		for(size_t e=0;e<att[x].size();e++){
			for(size_t f=0;f<att[y].size();f++){
				ans=min(ans,zdl[att[x][e]][att[y][f]]+b[x][e]+b[y][f]+w[x]+w[y]);	 
			}
		}
		
		kuaixie(ans);
		putchar('\n');
	}
	
	return 0;
}
