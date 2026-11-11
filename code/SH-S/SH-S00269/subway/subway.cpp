#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0x3f3f3f3f;
int w[100005];
struct node{
	int l,t;
};
vector<vector<node> > v(100005);
vector<vector<int> > line(505);
bool vis1[100005];
bool vis2[505];
int start,e;
int check(int a,int b){
	int len=v[a].size();
	for(int i=0;i<len;i++){
		if(v[a][i].l==b) return i;
	}
}
void zhan(int p,int cnt,int end){
	if(p==end){
		ans=min(cnt,ans);
		return;
	}
	vis1[p]=true;
	int len=v[p].size();
	for(int i=0;i<len;i++){
		int nl=v[p][i].l;
		int t1=v[p][i].t;
		if(vis2[nl]) continue;
		vis2[nl]=true;
		int len2=line[nl].size();
		for(int i=0;i<len2;i++){
			int nz=line[nl][i];
			if(vis1[nz]) continue;
			int visit=check(nz,nl); 
			int time=v[nz][visit].t+t1;
			zhan(nz,cnt+time,end);
		}
		vis2[nl]=false;
	}
	vis1[p]=false;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,A,T;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>A>>T;
			line[i].push_back(A);
			v[A].push_back({i,T});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start>>e;
		ans=0x3f3f3f3f;
		memset(vis1,false,sizeof vis1);
		memset(vis2,false,sizeof vis2);
		zhan(start,0,e);
		ans+=w[start]+w[e];
		cout<<ans<<endl;
	}
	return 0;
}
