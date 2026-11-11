#include<bits/stdc++.h>
using namespace std;
const long long INF=1e9;
long long z[105],s[105],up[105],son[105],min1[105],min2[105],cnt,an,ans,ceshidian,n,m;
vector<long long> v[105];
void cl(long long x){
	s[x]=0;
	for(long long i:v[x]){
		if(s[i])cl(i);
	}
}
void df1(long long x,long long fa){
	min1[x]=min2[x]=INF;
	if(z[x]){
		min1[x]=0;
	}
	for(long long i:v[x]){
		if(i==fa)continue;
		df1(i,x);
		if(min1[x]>=min1[i]+1){
			min2[x]=min1[x];
			min1[x]=min1[i]+1;
			son[x]=i;
		}else if(min2[x]>=min1[i]){
			min2[x]=min1[i];
		}
	}
}
void df2(long long x,long long fa){
	if(z[x])up[x]=0;
	for(long long i:v[x]){
		if(i==fa)continue;
		if(i==son[x])up[i]=min(up[x]+1,min2[x]+1);
		else up[i]=min(up[x]+1,min1[x]+1);
		df2(i,x);
	}
	an=max(an,min(up[x],min1[x]));
}
void dfs(long long p,long long lst){
	if(p==m){
		for(long long i=1;i<=n;i++){
			s[i]=z[i];
		}
		cnt=0;
		for(long long i=1;i<=n;i++){
			if(s[i]){
				cnt++;
				cl(i);
			}
		}
		if(cnt<=2){
			an=-INF;
			df1(1,0);
			up[1]=INF;
			df2(1,0);
			ans=min(ans,an);
		}
		return;
	}
	for(long long i=lst+1;i<=n;i++){
		if(i>n-(m-p-1))break;
		z[i]=1;
		dfs(p+1,i);
		z[i]=0;
	}
}
void slove(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		v[i].clear();
		v[i].shrink_to_fit();
	}
	for(long long i=1,a,b;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans=INF;
	dfs(0,0);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout);  
	cin>>ceshidian;
	long long T;
	cin>>T;
	while(T--)slove();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/