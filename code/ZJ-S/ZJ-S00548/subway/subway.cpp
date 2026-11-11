#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int to,l,nxt;
}a[1000005];
struct pp{
	int id,l;
	bool operator<(const pp &you)const{
		return l>you.l;
	}
};
int c,n,m,dd,Q,w[500005],cnt,he[500505],d[500505],ddd[2005][2005];
bool vv[500505];
vector<int> mp[500505];
priority_queue<pp> q;
queue<pp> qqq;
void add(int u,int vv,int w){
	cnt++;
	a[cnt].to=vv;
	a[cnt].l=w;
	a[cnt].nxt=he[u];
	he[u]=cnt;
}
void wk(){
	int ty;
	for(int i=1;i<=n;++i){
		int kk;
		cin>>kk;
		while(kk--){
			int aa,tt;
			cin>>aa>>tt;
			ty=tt;
			mp[aa].push_back(i+m);
			mp[i+m].push_back(aa);
		}
	}
	while(Q--){
		int ss,tt;
		cin>>ss>>tt;
	    for(int i=1;i<=n+m;++i)d[i]=0,vv[i]=0;
	    d[ss]=0;
	    qqq.push((pp){ss,0});
	    vv[ss]=1;
	    while(!qqq.empty()){
	    	int no=qqq.front().id,l=qqq.front().l;
	    	qqq.pop();
	    	for(int i=0;i<mp[no].size();++i){
	    		int v=mp[no][i];
	    		if(vv[v])continue;
	    		d[v]=l+ty;
	    		//cout<<l<<" "<<ll<<'\n';
	    	    vv[v]=1;
	    	    if(v==tt){
	    	    	while(!qqq.empty())qqq.pop();
	    	    	break;
				}
	    		qqq.push((pp){v,d[v]});
			}
		}
		cout<<w[ss]+w[tt]+d[tt]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>dd>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(12<=c&&c<=15){
		wk();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		while(kk--){
			int aa,tt;
			cin>>aa>>tt;
			add(i+m,aa,tt);
			add(aa,i+m,tt);
		}
	}
	while(Q--){
		int ss,tt;
		cin>>ss>>tt;
		if(ss<=2000&&tt<=2000&&ddd[ss][tt]){
			cout<<w[ss]+ddd[ss][tt]+w[tt]<<'\n';
			continue;
		}
	    for(int i=1;i<=n+m;i++)d[i]=1e18,vv[i]=0;
	    d[ss]=0;
	    q.push((pp){ss,0});
	    while(!q.empty()){
	    	int no=q.top().id,l=q.top().l;
	    	q.pop();
	    	if(vv[no])continue;
	    	vv[no]=1;
	    	for(int i=he[no];i;i=a[i].nxt){
	    		int v=a[i].to,ll=a[i].l;
	    		if(d[v]>l+ll){
	    			d[v]=l+ll;
	    			q.push((pp){v,d[v]});
				}
			}
		}
		if(ss<=2000){
			for(int i=1;i<=std::min(2000ll,m);i++)ddd[ss][i]=ddd[i][ss]=d[i];
		}
		cout<<d[tt]+w[ss]+w[tt]<<'\n';
	}
	return 0;
}

