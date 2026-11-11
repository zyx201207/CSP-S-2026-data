#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=5e3+5;
#define ll long long
ll qrd(){
	char c;ll ret=0;
	int sign=1;
	do{
		c=getchar();
		if(c=='-')sign=-1;
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret*sign;
}
int c,T,n;
ll x[N],d;
vector<int> to[M];
int in[M],ind[M];
int f[M][M],g[M][M];
void Top1(int s){
	memset(f[s],0x3f,sizeof f[s]);
	queue<int> q;
	q.push(s);
	f[s][s]=0;
	for(int i=s;i<=n;i++)ind[i]=in[i];
	for(int u=1;u<s;u++)
		for(auto v:to[u])ind[v]--;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:to[u]){
			f[s][v]=min(f[s][v],f[s][u]+1);
			if(!(--ind[v]))q.push(v);
		}
	}
}
int tmp[M];
void Top2(int s){
	memset(tmp,0x3f,sizeof tmp);
	queue<int> q;
	q.push(s);
	tmp[s]=0;g[s][s]=1;
	for(int i=s;i<=n;i++)ind[i]=in[i];
	for(int u=1;u<s;u++)
		for(auto v:to[u])ind[v]--;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto v:to[u]){
			if(tmp[u]+1==f[s][v])g[s][v]+=g[s][u];
			tmp[v]=min(tmp[v],tmp[u]+1);
			if(!(--ind[v]))q.push(v);
		}
	}
}
void solve1(){
	memset(g,0,sizeof g);
	for(int i=1;i<=n;i++){
		x[i]=qrd();
		in[i]=0;
		for(int j=1;j<i;j++){
			if(x[i]-x[j]<=d){
				to[j].push_back(i);
				in[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++)Top1(i);
	for(int i=1;i<=n;i++)Top2(i);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}
ll y[N];
int num[N];
void solve2(){
	for(int i=1;i<=n;i++){
		x[i]=qrd();
		y[n-i+1]=-x[i];
	}
	for(int i=1;i<=n;i++){
		int pos=upper_bound(y+1,y+1+n,y[i]+d)-y-1;
		if(pos>i+1)num[n-pos+1]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int pos=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		if(pos>i+1)ans+=num[pos-1];
	}
	printf("%lld\n",ans);
}
void solve3(){
	if(n==1){
		puts("0");
		return;
	}
	for(int i=1;i<=n;i++)x[i]=qrd();
	ll dd=x[2]-x[1];
	int num=d/dd+1;
	ll ans=0;
	if(num>(n+1)/2||num<3)ans=0;
	else ans=n-2*num+3;
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=qrd();T=qrd();
	while(T--){
		n=qrd();d=qrd();
		if(c<=10)solve1();
		else if(c==13||c==14)solve2();
		else if(c==11||c==12)solve3();
		for(int i=1;i<=n;i++)to[i].clear();
	}
	return 0;
}