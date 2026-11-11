#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,N,M,D,Q,tEX,Startst,Endst,ANS;
struct edge{
	int endst;
	int theline;
};
struct bianli{
	int w;
	int theline;
};
vector<int> T[500010];
vector<edge> A[500010];
int W[500010];
int DIS[500010];
int bfs(){
	queue<int>Q;
	DIS[Startst]+=T[Startst][0];
	Q.push(Startst);
	while(!Q.empty()){
		int w=Q.front();
		Q.pop();
		for(int i=0;i<A[w].size();i++){
			edge ttt=A[w][i];
			if(DIS[ttt.endst]<DIS[w]+T[ttt.endst][0]+T[ttt.endst][1]){
				DIS[ttt.endst]=DIS[w]+T[ttt.endst][0]+T[ttt.endst][1];
			}
		}
	}
	return DIS[Endst];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>W[i];
	}
	for(int i=1;i<=N;i++){
		cin>>tEX;
		int lastst=0;
		for(int j=1;j<=tEX;j++){
			int At,Tt;
			cin>>At>>Tt;
			T[At].push_back(Tt);
			if(i==1){
				lastst=At;
				continue;
			}
			edge t;
			t.endst=At;
			t.theline=i;
			A[lastst].push_back(t);
			t.endst=lastst;
			A[At].push_back(t);
			lastst=At;
		}
	}
	while(Q--){
		ANS=0;
		for(int i=1;i<=N;i++)DIS[i]=1e9;
		cin>>Startst>>Endst;
		DIS[Startst]=0;
		ANS+=bfs();
		ANS+=W[Startst]+W[Endst];
		cout<<ANS<<endl;
	}
}
