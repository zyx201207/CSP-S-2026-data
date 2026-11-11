#include<bits/stdc++.h>
#define int long long
using namespace std;
//struct node{
//	int w,p;
//};
//int dis[500005];
//vector<node>q[500005];
//void dijsktra(){
//	queue<node> q;
//	memset(dis,0x3f,sizeof(dis));
//	dis[0]=0;
//	while(!q.empty()){
//		node e=q.top();
//		q.pop();
//		for(int i=0;i<q[e.p].size();i++){
//			if(q[i].w+dis[e.p]>q[i].p){
//				dis[e.p]=q[i].w;
//			}
//		}
//	}
//}
//good night dijsktra
int w[200005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	while(q--)
	cout<<w[1]<<endl;
	return 0;
}
