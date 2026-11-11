#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],mx=0,n,m,pow2[35],b[32],ww[N],c[N];//ww[i]:去除第i个数后增大的量 
bool s[N][32];
void dfs(int i,int sum,int cnt){
	if(cnt==m){
		mx=max(sum,mx);
		return;
	}
	if((i>n&&cnt<m)||(n-i+1)<m-cnt) return;
	if(sum==0){
		dfs(i+1,a[i],cnt+1);
	}else dfs(i+1,sum&a[i],cnt+1);
	dfs(i+1,sum,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	pow2[0]=1;
	pow2[1]=2;
	bool f1=1,f2=1;
	for(int i=2;i<=31;i++){
		pow2[i]=pow2[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) f2=0;
		bool f3=0;
		for(int j=0;j<=31;j++){
			if(a[i]+1==pow2[j]){f3=1;break;}
		}
		if(f3==0)f1=0;
		int x=a[i],w=1;
		while(x>0){
			s[i][w]=x%2;
			x/=2;
			w++;
		}
	}
	c[1]=a[1];
	for(int i=2;i<=n;i++)c[i]=c[i-1]&a[i];
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			b[i]+=s[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=31;j++){
			if(s[i][j]==0&&n-b[j]-1==0) ww[i]+=pow2[j];
		}
	}
	if(m==n-1){
		sort(ww+1,ww+1+n);
		cout<<c[n]+ww[n];
		return 0;
	}
	bool f4=0;
	for(int i=0;i<=31;i++){
		if(n==pow2[i])f4=1; 
	}
	if(f4==0) f2=0;	
	if(m==1){
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(f1){sort(a+1,a+1+n);cout<<a[n-m+1];return 0;}
	if(f2){mx=a[n];for(int i=n-1;i>n-m;i--){mx&=a[i];}cout<<mx;return 0;}
	if(n<=20){dfs(1,0,0);cout<<mx;return 0;}
	if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++) mx&=a[i];
		cout<<mx;
		return 0;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++) mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;
	}
	sort(ww+1,ww+1+n);
	int ans=0;
	for(int i=n;i>=n-m+1;i--) ans+=ww[i];
	cout<<ans+c[n];
	return 0;
} 
