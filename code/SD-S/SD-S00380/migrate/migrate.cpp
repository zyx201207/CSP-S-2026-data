#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef __int128 lll;
bool __(char ch){return ch>='0'&&ch<='9';}
template<typename T> inline void read(T &x){
	x=0;char ch=gc();bool sgn=0;
	while(!__(ch)&&ch!=EOF)sgn|=(ch=='-'),ch=gc();
	while(__(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	if(sgn)x=-x;
}
template<typename T,typename ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
const int N=1e6+5;
ll n,d,x[N],f[N],nxt[N],pre[N],g[N];
void solve(){
	read(n,d);
	for(int i=1;i<=n;i++)read(x[i]);
//	for(int i=1;i<=n;i++)pre[i]=i;
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(x[j]-x[i]<=d)nxt[i]=j;
//		}
//		//pre[nxt[i]]=min(pre[nxt[i]],i);
//	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[j]=0x3f3f3f3f,g[j]=0;
		f[i]=0,g[i]=1;
		for(int j=i+1;j<=n;j++){
			int t=lower_bound(x+i,x+j,x[j]-d)-x;
			if(t==j)break;
			f[j]=f[t]+1;
			while(t<j){
				g[j]+=g[t];
				t++;
				if(f[j]!=f[t]+1)break;
				else if(g[j]>=3)break;
			}
			if(f[j]==0x3f3f3f3f)break;
			else{
				if(g[j]==2)ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;read(c,T);
	while(T--)solve();
	return 0;
}
/*
#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef __int128 lll;
bool __(char ch){return ch>='0'&&ch<='9';}
template<typename T> inline void read(T &x){
	x=0;char ch=gc();bool sgn=0;
	while(!__(ch)&&ch!=EOF)sgn|=(ch=='-'),ch=gc();
	while(__(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	if(sgn)x=-x;
}
template<typename T,typename ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
const int N=1e6+5;
__int128 n,d,x[N],f[N][2],nxt[N];
#define int long long
void solve(){
	read(n,d);
	for(int i=1;i<=n;i++)read(x[i]);
	for(int i=1;i<=n;i++){
		int t=upper_bound(x+i,x+n+1,x[i]+d)-x;
		nxt[i]=t-1;
		//pre[nxt[i]]=min(pre[nxt[i]],i);
	}
	for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
	for(int i=n;i>=1;i--){
		int cnt=0;
		if(nxt[nxt[i]]==nxt[i]){
			f[i][0]=nxt[i]-i;
			f[i][1]=0;
			continue;
		}
		int t1=lower_bound(x+i,x+nxt[i]+1,x[nxt[nxt[i]]]-d)-x;
		t1=(nxt[i]-t1);
		cnt=t1;
		int cnt1=0;
		int t=upper_bound(x+nxt[i],x+nxt[nxt[i]]+1,x[nxt[i]-1]+d)-x;
		t--;
		if(t>=nxt[i])cnt1=t-nxt[i];
		if(nxt[i]-1!=i){
			int t1=upper_bound(x+nxt[i],x+nxt[nxt[i]]+1,x[nxt[i]-2]+d)-x;
			t1--;
			if(t1>=nxt[i])cnt1-=(t1-nxt[i]);
		}
	//	cout<<cnt<<" "<<cnt1<<endl;
		if(cnt==0){
			f[i][1]=f[nxt[i]][1]+cnt1;
			f[i][0]=f[nxt[i]][0]+nxt[i]-i;
		}
		else if(cnt==1){
			f[i][1]=f[nxt[i]][0]+cnt1-(nxt[nxt[i]]-nxt[i]);
			f[i][0]=nxt[i]-i;
		}
		else{
			f[i][0]=nxt[i]-i;
			f[i][1]=0;
		}
	}
	ll ans=0;
//	cout<<endl;
	for(int i=1;i<=n;i++){
		ans+=f[i][1];
//	cout<<f[i][0]<<" "<<f[i][1]<<endl;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate3.out","w",stdout);
	int c,T;read(c,T);
	while(T--)solve();
	return 0;
}
*/ 
