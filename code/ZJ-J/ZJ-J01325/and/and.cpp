#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200005];
void dfs(int x,int p,int s){
	if(p==m){
		ans=max(ans,s);
		return;
	}
	if(x>n){
		return;
	}
	if(s==-1){
		dfs(x+1,p+1,a[x]);
	}
	else{
		dfs(x+1,p+1,s&a[x]);
	}
	dfs(x+1,p,s);
}
bool ek(int x){
	int p=1,t=0;
	while(p!=x&&t<=20){
		t++;
		p*=2;
	}
	if(p==x){
		return 1;
	}
	else{
		return 0;
	}
}
bool jy(){
	int s=1;
	for(int i=1;i<=n;i++)s=s&ek(a[i]+1);
	return s;
}
int cyc(int x){
	int res=0;
	while(x!=1){
		x/=2;
		res++;
	}
	return res;
}
int chyc(int x){
	int res=1;
	while(x!=0){
		res*=2;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	else if(m==n){
		int cnt;
		cnt=a[1];
		for(int i=2;i<=n;i++)cnt=cnt&a[i];
		cout<<cnt;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(jy()){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(ek(n)){
		int sp=cyc(n);
		cout<<chyc(sp-m+1);
	}
	else if(m==n-1){
		int f[n+5],f1[n+5];
		f[1]=a[1];
		for(int i=2;i<=n;i++)f[i]=f[i-1]&a[i];
		f1[n]=a[n];
		for(int i=n-1;i>=1;i--)f1[i]=f1[i+1]&a[i];
		f[0]=f[n+1]=pow(2,30)-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,f[i-1]&f1[i+1]);
		}
		cout<<ans;
	}
	else{
		dfs(1,0,-1);
		cout<<ans;
	}
	return 0;
}