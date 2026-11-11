#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
namespace IO{
	char *p1,*p2,buf[100000];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
	template<class T>
	inline void read(T &x){
		int f=1,ch=nc();x=0;
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=nc();
		}
		while(isdigit(ch)){
			x=(x<<3)+(x<<1)+ch-'0';
			ch=nc();
		}
		x*=f;
	}
	template<class T>
	void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
};
using namespace IO;
constexpr int N=1000005,INF=INT_MAX;
int C,T,n,m,k,x,y,top,mxL[N],mnR[N],r[N],fa[N],dep[N],maxl[N],maxl2[N],head[N],nxt[2*N],to[2*N];
int D,A,B,L,d[N];
bool vis[N];
inline void adde(int x,int y){
	nxt[++top]=head[x];
	to[top]=y;
	head[x]=top;
}
void Dfs(int x){
	maxl[x]=maxl2[x]=x;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa[x]) continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		Dfs(y);
		if(dep[maxl[y]]>dep[maxl[x]]){
			maxl2[x]=maxl[x];
			maxl[x]=maxl[y];
		}else if(dep[maxl[y]]>dep[maxl2[x]]){
			maxl2[x]=maxl[y];
		}
	}
	if(dep[maxl[x]]+dep[maxl2[x]]-2*dep[x]>D){
		D=dep[maxl[x]]+dep[maxl2[x]]-2*dep[x];
		A=maxl[x],B=maxl2[x],L=x;
	}
}
int Dfs2(int x,int fa,int P){
	int cnt=0;
	dep[x]=0;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa||vis[y]) continue;
		cnt+=Dfs2(y,x,P);
		dep[x]=max(dep[x],dep[y]+1);
	}
	return cnt+(dep[x]>=P);
}
bool check(int P){
	int ans=INF,cnt=0;
	for(int i=1;i<=m+1;i++) mnR[i]=INF;
	for(int i=1;i<=m;i++){
		cnt+=Dfs2(d[i],0,P);
		if(dep[d[i]]>=P){
			--cnt,r[i]=0;
		}else r[i]=P-dep[d[i]];
		if(i-r[i]>0) mnR[i-r[i]]=min(mnR[i-r[i]],i+r[i]);
//		cout<<r[i]<<" ";
	}
//	cout<<endl;
	mxL[m]=m-r[m];
	for(int i=m-1;i;i--){
		mnR[i]=min(mnR[i],mnR[i+1]);
		mxL[i]=max(i-r[i],mxL[i+1]);
	}
	for(int i=1,R=INF;i<=m;i++){
		R=min(R,i+r[i]);
		if(R>i) continue;
//		cout<<i<<":"<<endl;
		if(mnR[i+1]>m){
			ans=min(ans,i-R+1);
//			cout<<"Case1:"<<i-R+1<<endl;
		}else if(mxL[mnR[i+1]]<mnR[i+1]){
			ans=min(ans,(i-R+1)+1);
//			cout<<"Case2:"<<i-R+2<<endl;
		}else{
			ans=min(ans,(i-R+1)+(mxL[mnR[i+1]]-mnR[i+1]+1));
//			cout<<"Case3:"<<(i-R+1)+(mxL[mnR[i+1]]-mnR[i+1]+1)<<endl;
		}
	}
//	cout<<P<<": "<<ans<<endl;
	if(ans>k) return false;
	return ans+cnt<=k;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(C),read(T);
	while(T--){
		read(n),read(k);
		for(int i=1;i<=n;i++) vis[i]=false,head[i]=0;
		top=0,D=-1;
		for(int i=1;i<n;i++){
			read(x),read(y);
			adde(x,y);
			adde(y,x);
		}
		Dfs(1);
		for(int i=A,j=0;i!=L;i=fa[i]){
			d[++j]=i;
		} 
		d[dep[A]-dep[L]+1]=L;
		for(int i=B,j=D+2;i!=L;i=fa[i]){
			d[--j]=i;
		}
		m=D+1;
		for(int i=1;i<=m;i++){
//			cout<<d[i]<<" ";
			vis[d[i]]=true;
		}
//		cout<<endl;
		int l=0,r=m;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		write(r);
		puts("");
	}
}

