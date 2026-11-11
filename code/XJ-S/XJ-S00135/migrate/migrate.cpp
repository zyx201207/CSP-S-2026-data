#include<bits/stdc++.h>
using namespace std;
int c,t,n,MXXX=1e9;
long long d,x[2000006];
void solveA(){
	
}
int v1[5003],v2[5003],ans,lt[5003];
void dfs(int fa,int u,int b){
	if(b>v1[u])return;
	else if(b==v1[u])++v2[u];
	else if(b<v1[u]){
		v1[u]=b;
		v2[u]=1;
	}
	for(int i=lt[u];i>u;--i){
		dfs(u,i,b+1);
	}
}
void bl(){
	ans=0;
	for(int i=1;i<=n;++i){
		lt[i]=i;
		for(int j=i;j<=n;++j){
			if(x[j]-x[i]>d)break;
			lt[i]=j;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			v1[j]=MXXX;
			v2[j]=0;
		}
		dfs(-1,i,0);
		for(int j=i;j<=n;++j){
			if(v2[j]==2){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		if(n<4){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			solveA();
			continue;
		}else{
			bl();
			continue;
		}
	}
	return 0;
}

