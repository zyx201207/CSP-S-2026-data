#include<bits/stdc++.h>
#define int long long
using namespace std;
struct station{
	int w,con[510];
}s[35010];
int N,M,D,Q;
int Dijk(int fr,int to){
	int dis[M+5];
	for(int i=1;i<=M;i++){
		dis[i]=LLONG_MAX;
	}
	dis[fr]=0;
	queue<int> q;
	q.push(fr);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=M;i++){
			bool can=false;
			for(int j=1;j<=N;j++){
				if(dis[i]>dis[x]+s[x].con[j]+s[i].con[j]&&s[x].con[j]&&s[i].con[j]&&i!=x){
					dis[i]=dis[x]+s[x].con[j]+s[i].con[j];
					can=true;
				}
			}
			if(can){
				q.push(i);
			}
		}
	}
	return dis[to];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>N>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>s[i].w;
	}
	for(int i=1;i<=N;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			s[a].con[i]=t;
		}
	}
	while(Q--){
		int fr,to;
		cin>>fr>>to;
		cout<<s[fr].w+s[to].w+Dijk(fr,to)<<endl;
	} 
	return 0;
}
