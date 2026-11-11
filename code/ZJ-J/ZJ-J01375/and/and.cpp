#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],maxn=0,s;
void dfs(int t){
	if(t>m){
		maxn=max(maxn,s);
		return;
	}
	if(t==1){
		for(int i=1;i<=n;i++){
			s=a[i];
			b[i]=1;
			dfs(t+1);
			b[i]=0;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(b[i]!=1){
				s=s&a[i];
				b[i]=1;
				dfs(t+1);
				b[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	dfs(1);
	cout<<maxn;
	return 0;
}