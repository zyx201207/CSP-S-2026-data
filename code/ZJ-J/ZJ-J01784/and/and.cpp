#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
long long qpow(long long di,long long zhi){
	if(zhi==1) return di;
	if(zhi%2==0) return qpow(di*di,zhi/2);
	else return qpow(di*di,zhi/2)*di;
}
bool cmp(int x,int y){
	return x>y;
}
int n,m;
long long a[200005],ans=0;
void dfs(int t,long long cnt,int lt){
	if(cnt==0&&t!=0) return ;
	if(t==m){
		ans=max(ans,cnt);return ;
	}
	for(int i=lt;i<=n;i++){
		if(t==0) dfs(1,a[i],i+1);
		else dfs(t+1,a[i]&cnt,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n>2000&&n<=200000&&m!=n-1){
		sort(a+1,a+1+n,cmp);
		long long anst=a[1],k=1;
		for(int i=1;i<=30;i++){
			long long x=qpow(2,i);
			if(x>a[k]) break;
			if(x==anst){
				anst=a[++k];
				i=1;
			} 
		}
		if(k==m&&a[k]==a[1]){
			cout<<a[k];
			return 0;
		}
		for(int i=2;i<=m;i++){
			if(anst&a[i]==0) {m++;continue;}
			anst=anst&a[i];
		}
		cout<<anst;
		return 0;
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
