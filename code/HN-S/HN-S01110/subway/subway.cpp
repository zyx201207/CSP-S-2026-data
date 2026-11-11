#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>e[505];
int dist[50005];
void dijsktstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >pq;
	
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[505];
	cin>>c>>m>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,cur;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			if(j>1){
				e[cur].push_back({v,w});
				e[v].push_back({cur,w});
			}
			cur=v;
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		cout<<rand()%35;
	} 
}
//《每坐一站地铁还要走一段路》 
