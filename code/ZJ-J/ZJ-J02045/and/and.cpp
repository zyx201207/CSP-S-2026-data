#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'&&ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int lowbit(int x){
	return x&(-x);
}
int n,m;
int a[N];
int x;
int id;
int vis[N];
int p[35];
void dfs(int cc,int ans){
	if(cc>m) return;
	if(cc==m){
		x=max(x,ans);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(ans==0){
			dfs(cc+1,a[i]);
		}else{
			dfs(cc+1,ans&a[i]);
		}
		vis[i]=0;
	}
}
void init(){
	p[0]=1;
	p[1]=2;
	for(int i=2;i<=31;i++){
		p[i]=p[i-1]*2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==i-1) cnt++;
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(cnt==n){
		init();
		for(int j=1;j<=22;j++){
			int c=0;
			int xx=0;
			for(int i=1;i<=n;i++){
				if(a[i]<=p[j]&&a[i]>=p[j-1]){
					c++;
					if(xx==0) xx=a[i];
					else xx&=a[i];
				}
			}
			if(c>=m){
				cout<<xx;
				return 0;
			}
		}
		x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(n<=20){
		dfs(0,0);
		cout<<x;
		return 0;
	}
	
	for(int i=1;i<n;i++){
		if(lowbit(a[i])==lowbit(a[i]+1)){
			x=a[i];
			id=i;
			break;
		}
	}
	if(x==0||(n-id+1)<m) cout<<0;
	else{
		for(int i=id+1;i<=id+m-1;i++){
			x&=a[i];
		}
		cout<<x;
	}
	return 0;
}
