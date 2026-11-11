#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int c,t;
vector<int> tu[500005];
struct qnode{
	int term;
	int node;
};
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		int _u,_v;
		for(int i=1;i<n;i++){
			scanf("%d%d",&_u,&_v);
			tu[_u].push_back(_v);
			tu[_v].push_back(_u);
		}
		int Min=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			queue<qnode>q;
			bool vis[500005];
			qnode _q;
			_q.node=i;
			_q.term=0;
			q.push(_q);
			vis[i]=1;
			int cnt=1;
			int lastterm=0,term;
			while(!q.empty()){
				_q=q.front();
				term=_q.term;
				q.pop();
				bool bbb;
				for(auto l:tu[_q.node]){
					if(vis[l]) continue;
					cnt++;
					if(cnt==k){
						bbb=1;
						break;
					}
					_q.node=l;
					_q.term=term+1;
					q.push(_q);
				}
				lastterm=term;
				if(bbb) break;
			}
			Min=min(Min,lastterm+term+1);
		}
		printf("%d\n",Min);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*


*/