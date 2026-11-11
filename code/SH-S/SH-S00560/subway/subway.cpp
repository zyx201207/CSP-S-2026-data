#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int sta,t;
} aa;
struct bbb{
	int leng,xx;
} bb;
int c,n,m,d,qq,t;
int w[500005],a,k,cm[500005];
vector<aaa> vis[500005];
queue<bbb> q;
bool bi(aaa x,aaa y){
	return x.t<y.t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>qq;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			aa.sta=a;
			aa.t=t;
			vis[m+i].push_back(aa);
			aa.sta=i;
			vis[a].push_back(aa);
		}
	}
	for(int i=0;i<n+m;i++){
		sort(vis[i],vis[i]+vis[i].size(),bi);
	}
	for(int i=0;i<qq;i++){
		int st,en,ans=0;
		cin>>st>>en;
		bb.a=st;
		bb.leng=0;
		q.push(st);
		while(!q.empty()){
			bbb th=q.top();
			int len=vis[th.a].length();
			if(th.a==en){
				cout<<th.leng<<" ";
			}
			for(int j=0;j<len;j++){
				bb.a=vis[th.a][j].sta;
				bb.leng=th.leng+vis[th.a][j].t;
				q.push(bb);
			}
			q.pop();
		}
	}
	return 0;
} 
