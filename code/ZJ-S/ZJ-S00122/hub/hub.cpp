#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
long long c,t,n,k,U,V,num[10005],ans;
vector<long long> v[10005],vec;
bool pd[10005],T[10005],PD[10005];
queue<long long> Q;
void dfs(long long now){
	for(int i=0;i<v[now].size();i++){
		if(T[v[now][i]] && !pd[v[now][i]]){
			pd[v[now][i]]=true;
			dfs(v[now][i]);
			return ;
		}
	}
}
bool check1(){
	long long cc=0;
	for(int i=0;i<vec.size();i++){
		if(!pd[vec[i]]){
			pd[vec[i]]=true;
			dfs(vec[i]);
			cc++;
		}
	}
	return (cc<=2);
}
long long cal(long long I,long long J){
	for(int i=1;i<=n;i++){
		PD[i]=false;
		num[i]=0;
	}
	Q.push(I);PD[I]=true;num[I]=0;
	while(!Q.empty()){
		int F=Q.front();
		Q.pop();
		for(int i=0;i<v[F].size();i++){
			if(!PD[v[F][i]]){
				num[v[F][i]]=num[F]+1;
				PD[v[F][i]]=true;
				Q.push(v[F][i]);
			}
		}
	}
	return num[J];
}
long long calc(long long q){
	long long mx=0;
	for(int i=0;i<vec.size();i++){
		for(int j=1;j<=n;j++){
			if(T[j]){
				continue;
			}
			mx=max(mx,cal(vec[i],j));
		}
	}
	return mx;
}
long long gt(long long q){
	long long CNt=0;
	for(int i=1;i<=n;i++){
		T[i]=q%(1<<(i-1));
		if(T[i]){
			CNt++;
			vec.push_back(i);
		}
	}
	if(CNt!=k){
		return 1e18;
	}
	if(!check1()){
		return 1e18;
	}
	return calc(q);
}
int main(){
//	freopen("hub1.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	for(;t;t--){
		ans=1e18;
		n=read();k=read();
		for(int i=1;i<=n-1;i++){
			U=read();V=read();
			v[U].push_back(V);
			v[V].push_back(U);
		}
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++){
				pd[j]=false;
			}
			vec.clear();
			ans=min(ans,gt(i));
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}