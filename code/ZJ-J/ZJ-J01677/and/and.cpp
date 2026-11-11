#include<bits/stdc++.h>
using namespace std;
int tr[7000009][2],idx=1;;
int g[7000009];
int x[200009];
int c[39];
int s=30;
void add(int v){
	int u=0;
	for(int i=s;i>=0;i--){
		int t=(v>>i)&1;
		if(tr[u][t]){
			u=tr[u][t];
			g[u]++;
		}else{
			u=tr[u][t]=idx++;
			g[u]++;
		}
	}
}
int n,m;
void fun(){
	int u=0,ans=0;
	for(int i=s;i>=0;i--){
		if(g[tr[u][1]]>=m){
			u=tr[u][1];
			ans+=(1<<i);
		}else u=tr[u][0];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=30;j>=0;j--){
			int t=(x[i]>>j)&1;
			c[j]+=t;
		}
	}
	for(int i=30;i>=0;i--){
		if(c[i]>=m){
			s=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)add(x[i]);
	fun();
	return 0;
}
