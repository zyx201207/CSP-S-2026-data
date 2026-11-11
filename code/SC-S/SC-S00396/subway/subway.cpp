#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[20010],l[20010];
struct _time{
	int l;
	int tt;
};
vector <_time> t2[510];
vector <_time> t1[20010];
queue <int> q;
void init(int x){
	while(!q.empty())q.pop();
	q.push(x);
	l[x]=0;
	while(!q.empty()){
		for(int i=0;i<t1[q.front()].size();i++){
			for(int j=0;j<t2[t1[q.front()][i].l].size();j++){
				int uu=q.front(),vv=t2[t1[q.front()][i].l][j].l;
				int ll=t1[q.front()][i].l;
				if(l[vv]>l[uu]+t1[q.front()][i].tt+t2[t1[q.front()][i].l][j].tt){
					l[vv]=l[uu]+t1[q.front()][i].tt+t2[t1[q.front()][i].l][j].tt;
					q.push(vv);
					
				}
			}
		}
		q.pop();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,bb;
			cin>>aa>>bb;
			t1[aa].push_back({i,bb});
			t2[i].push_back({aa,bb});
		}
	}
	for(int i=1;i<=Q;i++){
		int xx,yy;
		cin>>xx>>yy;
		memset(l,0x3f,sizeof(l));
		init(xx);
		
		cout<<l[yy]+w[xx]+w[yy]<<endl;
	}
	return 0;
}
 