#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
int a[200001];
int p[200005][50];
void jfyput(int s,int a){
	int i=0;
	int base=1;
	for(int j=1;j<=30;j++)base*=2;
	while(a>0){
		if(a>=base)a-=base,p[s][i]=1;
		base/=2;
		i++;
	}
	p[s][40]=1;
	return;
}
int ans;
int maxn;
int sss;
void dfs(int i,int s,int l){
	if(l==m){
		maxn=max(maxn,s);
		return;
	}
	if(i>n){
		if(l!=m)return;
		maxn=max(maxn,s);
		return;
	}
	dfs(i+1,s,l);
	dfs(i+1,s&a[i],l+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jfyput(i,a[i]);
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(i+1,a[i],1);
		}
		cout<<maxn;
		return 0;
	}
	if(n<=2000){
		if(m==1){
			maxn=0;
			for(int i=1;i<=n;i++){
				maxn=max(maxn,a[i]);
			}
			cout<<maxn;
		}
		else if(m==n){
			maxn=a[1];
			for(int i=2;i<=n;i++)maxn=maxn&a[i];
			cout<<maxn;
		}else{
			maxn=0;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
			cout<<maxn;
		}
		return 0;
	}
	if(n<=200000){
		if(m==n-1){
			for(int i=1;i<=2;i++){
				dfs(i+1,a[i],1);
			}
			cout<<maxn;
			return 0;
		}
		int sss=1;
		for(int i=1;i<=n;i++){
			if(a[i]>4)sss=0;
		}
		if(sss){
			int l=40;
	long long base=(long long)(pow(2,31));
	for(int j=0;j<=30;j++){
		int k=0;
		for(int i=1;i<=n;i++){
			if(p[i][j]==1&&p[i][j]==p[i][l])k++;
		}
		base/=2;
		if(k<m)continue;
		l=j;
		ans+=base;
	}
	cout<<ans;
			return 0;
		}else{
			sort(a+1,a+1+n,greater<int>());
			cout<<a[m];
			return 0;
		}
		
	}
	
	return 0;
}
//75p 11:26