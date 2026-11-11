#include<bits/stdc++.h>
#define AC signed
#define AK return 0
#define int long long
using namespace std;
const string fwbs="This cpp is written by @hjcz_huls.";
const int N=2e5+10;
int a[N],s[30],n,m,maxn,maxans,tmp,p,t;
bool st[N][30],bl[N][30];
int fp(int n){
	int s=1;
	for(int i=1;i<=n;i++) s*=2;
	return s-1;
}
void change(int i,int x){
	int k=1;
	while(x) st[i][k++]=x%2,x/=2;
}
bool chaange(int x){
	if(!x) return 0;
	while(x){
		if(x%2==0) return 0;
		x/=2;
	}
	return 1;
}
void dfs(int x,int k,int ans){
	if(k==m){
		maxans=max(maxans,ans);
		return;
	}
	if(x>n) return;
	dfs(x+1,k+1,ans&a[x]);
	dfs(x+1,k,ans);
}
bool checkA(){
	for(int i=1;i<=n;i++) if(!chaange(a[i])) return 0;
	return 1;
}
bool checkB(){
	int x=n;
	while(x>1){
		if(x%2) return 0;
		x/=2;
	}
	for(int i=1;i<=n;i++) if(a[i]!=i-1) return 0;
	return 1;
}
AC main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	tmp=fp(ceil(log2(maxn)));
	if(m==1){
		cout<<maxn;
		AK;
	}
	if(m==n){
		for(int i=1;i<=n;i++) tmp&=a[i];
		cout<<tmp;
		AK;
	}
	if(m==2){
		for(int i=1;i<n;i++)
		  for(int j=i+1;j<=n;j++)
		    maxans=max(maxans,a[i]&a[j]);
		cout<<maxans;
		AK;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++) change(i,a[i]);
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=25;j++)
			if(!st[i][j]) s[j]++;
		for(int i=1;i<=25;i++)
		  if(s[i]==1)
		    for(int j=1;j<=n;j++)
			  if(!st[j][i]) bl[j][i]=1;
		for(int i=1;i<=n;i++) tmp&=a[i];
		change(n+1,tmp);
		for(int i=1;i<=n;i++){
			p=0,t=1;
			for(int j=1;j<=25;j++) if(bl[i][j]) st[n+1][j]=1;
			for(int j=1;j<=25;j++) p+=st[n+1][j]*t,t*=2;
			maxans=max(maxans,p);
			change(n+1,tmp);
		}
		cout<<maxans<<' ';
	}
	if(checkA()){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		AK;
	}
	if(checkB()){
		cout<<n-fp(ceil(log2(m)))-1<<' ';
		AK;
	}
	dfs(1,0,fp(ceil(log2(maxn))));
	cout<<maxans;
	AK;
}