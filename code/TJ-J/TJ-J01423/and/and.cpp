#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
bool vis[105];
int b[200005];
int c[200005];
int n,m,maxnn=-1,flag4=1,pot0,pot1,pot2,pot3;
void go(int i,int p,int ans){
	if(p==m){
		maxnn=max(maxnn,ans);
		return;
	}
	if(i==n+1) return;
	vis[i]=1;
	go(i+1,p+1,ans&a[i]);
	vis[i]=0;
	go(i+1,p,ans);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) flag4=0;
	}
	if(flag4){
		for(int i=1;i<=n;i++){
			if(a[i]==0) pot0++;
			else if(a[i]==1) pot1++;
			else if(a[i]==2) pot2++;
			else pot3++;
		}
		if(pot3>=m) cout<<3;
		else if(pot3+pot2>=m) cout<<2;
		else if(pot3+pot2+pot1>=0) cout<<1;
		else cout<<0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}else if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) maxn=max(maxn,(a[i]&a[j]));
		}
		cout<<maxn;
	}else if(m==n-1){
		int maxn=-1;
		b[1]=a[1];
		for(int i=2;i<=n;i++) b[i]=b[i-1]&a[i];
		c[n]=a[n];
		for(int i=n-1;i>=1;i--) c[i]=c[i+1]&a[i];
		for(int i=1;i<=n;i++){
			if(i==1) maxn=max(maxn,c[2]);
			else if(i==n) maxn=max(maxn,b[n-1]);
			else maxn=max(maxn,(b[i-1]&c[i+1]));	
		}
		cout<<maxn;
	}else{
		go(1,0,0x7ffffff);
		cout<<maxnn;
	}
	return 0;
}
