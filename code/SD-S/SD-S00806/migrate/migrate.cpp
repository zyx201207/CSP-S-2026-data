#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int min(int x,int y){
	return (x<y)?x:y;
}
int max(int x,int y){
	return (x>y)?x:y;
}
const int N=2e6+5,inf=1e18;
int n,m;
int a[N];
int pre[N],nxt[N];
int pr[N],nt[N];//i往前符合要求的 =nxt 和是多少
int cp[N],cq[N];//nxt=i 的个数 
void clear(){
	for(int i=1;i<=n;i++){
		a[i]=pre[i]=nxt[i]=pr[i]=nt[i]=cp[i]=cq[i]=0;
	}
}
void sl(){
	clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	int pt=0;
	for(int i=1;i<=n;i++){
		while(pt<n&&a[pt+1]-a[i]<=m)pt++;
		nxt[i]=pt;
		cp[nxt[i]]++;
	}
	pt=n;
	for(int i=n;i>=1;i--){
		while(pt-1&&a[i]-a[pt-1]<=m)pt--;
		pre[i]=pt;
		cq[pre[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(nxt[pre[i]]!=i){
			pr[i]=0; 
		}
		else if(pre[i]!=i){
			pr[i]=pr[pre[i]]+cp[pre[i]];
		}
	}
	for(int i=n;i>=1;i--){
		if(pre[nxt[i]]!=i){
			nt[i]=0;
		}
		else if(nxt[i]!=i)nt[i]=nt[nxt[i]]+cq[nxt[i]];
	}
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]>m)continue;
		int cntx=cp[i+1],cnty=cq[i];
		if(pre[i]!=i&&nxt[pre[i]]==i+1){
			cntx+=pr[pre[i]]+cp[pre[i]];
		}
		if(nxt[i+1]!=i+1&&pre[nxt[i+1]]==i){
			cnty+=nt[nxt[i+1]]+cq[nxt[i+1]];
		}
		if(nxt[i]==i+1)cntx--;
		if(nxt[i+1]==i+1)cntx--;
		if(pre[i+1]==i)cnty--;
		if(pre[i]==i)cnty--;
		ans+=cntx*cnty;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=read(),t=1;
	t=read();
	while(t--)sl();
	return 0;
}
/*
现在是16:10，优势在我！ 
拍了1组成功出错，这特么怎么过的大样例 
*/
