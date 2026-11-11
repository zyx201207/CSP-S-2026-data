/*
f	01=  001->xx1 fpq
g	07=  ?21->xx1 fpq
h	02=  002->xx2 hl
l	08=  ?22->xx2 hl
p	04=  011->x21 fghlpq
q	12=  !11->x21 fghlpq
*/
#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int n,d,x[N],nxt[N],ans;
int f[N],g[N],h[N],l[N],p[N],q[N];
void ast(bool x){
	if(!x){
		clog<<"bao!\n";
		exit(0); 
	}
} 
void F(int i){
	if(!f[i])return;
	int li0=nxt[i]-i;
	if(li0==1){
		f[nxt[i]]+=f[i];
	}
	if(li0==2){
		p[nxt[i]]+=f[i];
	}
	if(li0>=3){
		q[nxt[i]]+=f[i];
	}
}
void G(int i){
	if(!g[i])return;
	int li0=nxt[i]-i;
	int li1=nxt[i-1]-i;
	ast(li1>=0);
	li0-=li1;
	if(li0==1){
		if(li1==0){
			f[nxt[i]]+=g[i];
		}
		if(li1>=1){
			g[nxt[i]]+=g[i];
		}
	}
	if(li0==2){
		if(li1==0){
			p[nxt[i]]+=g[i];
		}
		if(li1>=1){
			q[nxt[i]]+=g[i];
		}
	}
	if(li0>=3){
		q[nxt[i]]+=g[i];
	}
}
void H(int i){
	if(!h[i])return;
	int li0=nxt[i]-i;
	if(li0==1){
		h[nxt[i]]+=h[i];
	}
	if(li0>=2){
		l[nxt[i]]+=h[i];
	}
	ans+=li0*h[i];
}
void L(int i){
	if(!l[i])return;
	int li0=nxt[i]-i;
	int li1=nxt[i-1]-i;
	ast(li1>=0);
	li0-=li1;
	if(li0==1){
		if(li1==0){
			h[nxt[i]]+=l[i];
		}
		if(li1>=1){
			l[nxt[i]]+=l[i];
		}
	}
	if(li0>=2){
		l[nxt[i]]+=l[i];
	}
	ans+=li0*l[i];
}
void P(int i){
	if(!p[i])return;
	int li0=nxt[i]-i;
	int li1=nxt[i-1]-i;
	ast(li1>=0);
	li0-=li1;
	if(li0==0){
		if(li1==1){
			h[nxt[i-1]]+=p[i];
		}
		if(li1>=2){
			l[nxt[i-1]]+=p[i];
		}
	}
	if(li0==1){
		if(li1==0){
			f[nxt[i]]+=p[i];
		}
		if(li1>=1){
			g[nxt[i]]+=p[i];
		}
	}
	if(li0==2){
		if(li1==0){
			p[nxt[i]]+=p[i];
		}
		if(li1>=1){
			q[nxt[i]]+=p[i];
		}
	}
	if(li0>=3){
		q[nxt[i]]+=p[i];
	}
	ans+=li1*p[i];
}
void Q(int i){
	if(!q[i])return;
	int li0=nxt[i]-i;
	int li1=nxt[i-1]-i;
	int li2=nxt[i-2]-i;
	ast(li2>=0);
	li0-=li1,li1-=li2;
	if(li0==0){
		if(li1==1){
			if(li2==0){
				h[nxt[i-1]]+=q[i];
			}
			if(li2>=1){
				l[nxt[i-1]]+=q[i];
			}
		}
		if(li1>=2){
			l[nxt[i-1]]+=q[i];
		}
	}
	if(li0==1){
		if(li1==0){
			if(li2==0){
				f[nxt[i]]+=q[i];
			}
			if(li2>=1){
				g[nxt[i]]+=q[i];
			}
		}
		if(li1>=1){
			g[nxt[i]]+=q[i];
		}
	}
	if(li0==2){
		if(li1==0){
			if(li2==0){
				p[nxt[i]]+=q[i];
			}
			if(li2>=1){
				q[nxt[i]]+=q[i];
			} 
		}
		if(li1>=1){
			q[nxt[i]]+=q[i];
		}
	}
	if(li0>=3){
		q[nxt[i]]+=q[i];
	}
	ans+=li1*q[i];
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	nxt[0]=0;
	for(int i=1;i<=n;i++){
		nxt[i]=nxt[i-1];
		while(nxt[i]<n&&x[i]+d>=x[nxt[i]+1]){
			++nxt[i];
		}
		ast(nxt[i]>=i);
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	for(int i=1;i<=n;i++){
		F(i),H(i);
		if(i>=2){
			G(i),L(i),P(i);
		}
		if(i>=3){
			Q(i);
		}
//		clog<<'f'<<f[i]<<' ';
//		clog<<'g'<<g[i]<<' ';
//		clog<<'h'<<h[i]<<' ';
//		clog<<'l'<<l[i]<<' ';
//		clog<<'p'<<p[i]<<' ';
//		clog<<'q'<<q[i]<<' ';
//		clog<<ans<<'\n';
	}
	cout<<ans<<'\n';
	ans=0;
	for(int i=1;i<=n;i++){
		x[i]=0,nxt[i]=0;
		f[i]=g[i]=h[i]=l[i]=p[i]=q[i]=0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
	cin>>T>>T;
	while(T--){
		solve();
	}
	return 0;
}
