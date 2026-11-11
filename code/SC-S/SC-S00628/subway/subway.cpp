#include<bits/stdc++.h>
using namespace std;
int n,m,d,e,w[10009],head[10009],net[10009],l[10009],k[509],to[10009],cnt;
int x,y;
bool p[10009];
map<int,int> di[10009];
struct Q{
	int u,s;
	bool operator <(const Q& zx)const{
		return s>zx.s;
	}
};
priority_queue<Q> q;
void hb(int u,int v,int w){
	to[++cnt]=v;
	net[cnt]=head[u];
	head[u]=cnt;
	l[cnt]=w;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>e;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int uu,ww;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int z=1;z<=k[i];z++){
			cin>>uu>>ww;
			hb(uu+n,i,ww);
			hb(i,uu+n,ww);
		}
	}
	for(int i=1;i<=e;i++){
		cin>>x>>y;
		x+=n;y+=n;
		if(p[x]){
			cout<<di[x][y]+w[x-n]+w[y-n]<<"\n";
		}else{
			bool pp[60009]={0};
			for(int i=1;i<=m+n;i++)di[x][i]=1000000000;
			di[x][x]=0;
			q.push({x,0});
			while(q.size()){
				int u=q.top().u;
				int s=q.top().s;
//				cout<<u<<" "<<s<<"\n";
				q.pop();
				if(pp[u])continue;
				else{
					for(int i=head[u];i;i=net[i]){
//							cout<<to[i]<<"\n";
						if(s+l[i]<di[x][to[i]]){
							di[x][to[i]]=s+l[i];
//							cout<<to[i]<<" "<<u<<"    -\n";
							q.push({to[i],di[x][to[i]]});
						}
					}
				}
				pp[u]=1;
			}
			cout<<di[x][y]+w[x-n]+w[y-n]<<"\n";
		}
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2
*/