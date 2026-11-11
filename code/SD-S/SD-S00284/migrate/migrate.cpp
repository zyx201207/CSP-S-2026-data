#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
#define rint FastRead()
#define wint FastWrite

int FastRead() {
	int ans=0,sgn=0,ch=getchar();
	while(ch==' '||ch=='+'||ch=='\r'||ch=='\n') ch=getchar();
	if(ch=='-') ch=getchar(),sgn=1;
	while(ch>='0'&&ch<='9') ans=(ans<<1)+(ans<<3)+(ch^48),ch=getchar();
	return sgn?-ans:ans;
}
void FastWrite(int x) {
	if(x<0) x=-x,putchar('-');
	if(x>9) wint(x/10);
	putchar(x%10+'0');
}

const int N=2e6+10;
const int INF=1e9;

int p[N],nxt[N],pos[N],neg[N],flag[N],tmp;

void dfs(int u,int v,int step,int maxs) {
	if(u==v) {tmp++;return;}
	if(step>=maxs) return ;
	for(int i=min(nxt[u],v);i>=u;i--) 
		dfs(i,v,step+1,maxs);
}

void Solve() {
	int n,d; cin>>n>>d; 
	for(int i=1;i<=n;i++) flag[i]=0,pos[i]=0;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1,j=1;i<=n;i++) {
		while(j<=n && p[j]-p[i]<=d) j++;
		nxt[i]=j-1;
//		cerr<<nxt[i]<<' ';
	}//cerr<<'\n';
	int cnt=0,lstflg=0,ww3733a=0,flag2=1;
	ww3733a=p[2]-p[1];
	for(int i=1;i<=n;i++) {
		if(i>2) {
			if(ww3733a!=p[i]-p[i-1]) flag2=0;
		}
		if(p[i]-p[1]<=d && p[n]-p[i]<=d) {
			flag[i]=1;cnt++,lstflg=i;
//			cerr<<i<<' ';
		}
	}
	if(cnt>0) {
		if(cnt!=2) return cout<<"0\n",void();
		ll ans=0;
		for(int i=1;i<=n && !flag[i];i++) {
			if(flag[nxt[i]]) ans+=n-lstflg;
			else ans+=n-nxt[i];
		}
		cout<<ans<<'\n';
		return ;
	}
	if(flag2) {
		
	}ll ans=0;
	for(int k=1;k<=n;k++) {
		pos[k]=0; int step=1;
		for(int i=k;;) {
			int l=i+1,r=nxt[i];
			for(int j=l;j<=r;j++) pos[i]=step;
			step++;
			i=r;
			if(nxt[i]==i) {
				for(int j=nxt[i]+1;j<=n;j++) pos[i]=INF;
				
				break;
			}
			if(r>=n)break;
		}
		for(int j=k+3;j<=n;j++) {
			tmp=0;
			if(pos[j]==INF) continue;
			dfs(k,j,0,pos[j]);
			if(tmp==2) ans++;
		} 
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int c,t; cin>>c>>t;
	while(t--) Solve();
	return 0;
}

