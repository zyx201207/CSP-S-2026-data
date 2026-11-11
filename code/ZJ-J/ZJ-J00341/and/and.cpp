#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],k=-1,vis[N],u=0,q=0;
int jz(int a, int b){
	int a1[10],a2[10],b1=0,b2=0,k=0;
	while(a!=0){
		int s=a%2;
		b1++;
		a1[b1]=s;
		a/=2;
	}
	while(b!=0){
		int s=b%2;
		b2++;
		a2[b2]=s;
		b/=2;
	}
	for(int i=min(b1,b2);i>=1;i*=2)
		if(a1[i]==1&&a2[i]==1)
		  k+=i;
	return k;
}
int dfs(int w,int s,int gs){
	if(gs==m){
	return s;
	}
	for(int i=w;i<=n;i++){
		if(vis[i]==1)continue;
		if(s==0)s=a[i];
		else s=jz(s,a[i]);
		gs++;
		vis[i]=1;
		dfs(i,s,gs);
		vis[i]=0;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u=max(u,a[i]);
	}
	if(m==1){
	  cout<<u;
	  return 0;
	}
	if(m==2){
		q=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){
			  q=max(q,jz(a[i], a[j]));
			  cout<<q<<" ";
			}	
		cout<<q<<" ";
		return 0;
	}
	else {
		k=max(k,dfs(1,0,0));
		cout<<k;
	}
	return 0;
}
