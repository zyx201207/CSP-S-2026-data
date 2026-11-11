#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=5e5+7;
struct coord{
	int bian;
	int quxian;
};
vector<coord> s[N];
int w[N];
int n,m;
int c,d,q;
int x,t;
int u[N];
int y;
int zhi[N];
bool shi[N];
deque<coord>dq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>u[j]>>t;
		}
		for(int j=1;j<x;j++){
			s[u[j]].push_back({i,u[j+1]});
			s[u[j+1]].push_back({i,u[j]});
		}
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			shi[i]=false;
		}
		shi[x]=true;
		zhi[x]=0;
		while(!dq.empty()){
			dq.pop_back();
		}
		for(coord eee:s[x]){
			dq.push_front(eee);
			zhi[eee.quxian]=t;
			shi[eee.quxian]=true;
		}
		while(!dq.empty()){
			if(shi[y]==true){
				break;
			}
			coord xxx=dq.front();
			dq.pop_front();
			int ans=xxx.bian;
			int tmp=xxx.quxian;
			for(coord eee:s[tmp]){
				int i=eee.bian;
				int j=eee.quxian;
				if(shi[j]){
					continue;
				}
				shi[j]=true;
				if(i==ans){
					zhi[j]=zhi[tmp];
					dq.push_front({i,j});
				}else{
					zhi[j]=zhi[tmp]+2*t;
					dq.push_back({i,j});
				}
			}
		}
		cout<<zhi[y]+t+w[x]+w[y]<<endl;
	}
}
