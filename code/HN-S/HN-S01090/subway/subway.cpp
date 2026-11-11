#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,rn,sn,d,m,t[N],t1[N];
struct S{
	int next,time;
};
vector<S>v[N];
void bfs(int s,int e){
	queue<int>q;
	q.push(s);
	memset(t,-1,sizeof(t));
	t[s]=0;
	t[e]=1e9+7;
	while(q.size()){
		int far=q.front();
		q.pop();
		for(auto son:v[far]){
			if(son.next!=e){
				if(t[son.next]!=-1)continue;
				q.push(son.next);
				t[son.next]=t[far]+son.time;
			}else{
				t[e]=min(t[far]+son.time,t[e]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>rn>>sn>>d>>m;
	for(int i=1;i<=sn;i++)cin>>t1[i];
	for(int i=1,rsn;i<=rn;i++){
		cin>>rsn;
		for(int j=1,rs,t2;j<=rsn;j++){
			cin>>rs>>t2;
			v[rs].push_back({sn+i,t2});
			v[sn+i].push_back({rs,t2});
		}
	}
	for(int i=1,s,e;i<=m;i++){
		cin>>s>>e;
		bfs(s,e);
		cout<<t[e]+t1[e]+t1[s]<<endl;
	}
	return 0;
}

