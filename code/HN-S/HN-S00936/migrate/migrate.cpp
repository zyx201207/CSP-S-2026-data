#include<bits/stdc++.h>
#define int long long
using namespace std;
struct side{
	int d,cnt;
};
int T,N,M,x[50010],cnt;
void Dijk(int fr){
	side dis[50010];
	for(int i=1;i<=N;i++){
		dis[i].d=LLONG_MAX;
		dis[i].cnt=0;
	}
	dis[fr].d=0;
	dis[fr].cnt=1;
	queue<int> q;
	q.push(fr);
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		for(int i=1;i<=N;i++){
			if(dis[i].d>dis[pos].d+1&&abs(x[pos]-x[i])<=M){
				dis[i].d=dis[pos].d+1;
				dis[i].cnt=dis[pos].cnt;
				q.push(i);
			}
			else if(dis[i].d==dis[pos].d+1&&abs(x[pos]-x[i])<=M){
				dis[i].cnt+=dis[pos].cnt;
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(dis[i].cnt==2){
			cnt++;
		}
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>T;
	while(T--){
		cin>>N>>M;
		for(int i=1;i<=N;i++){
			cin>>x[i];
		}
		for(int i=1;i<=N;i++){
			Dijk(i);
		}
		cout<<cnt/2<<endl;
		cnt=0;
	}
	return 0;
}
