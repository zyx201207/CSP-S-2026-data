#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int c,t,n,k,u,v,fa[N],ans,a[N],d,cnt;
vector<int> to[N];
pair<int,int> p1,p2,r;
pair<int,int> find1(int x){
	pair<int,int> anss=make_pair(x,0);
	for(int i=0;i<to[x].size();i++){
		if(to[x][i]==fa[x])continue;
		fa[to[x][i]]=x;
		r=find1(to[x][i]);
		if(r.second>anss.second)anss=r;
	}anss.second++;
	return anss;
} 
int find2(int x,int d1,int d2){
	int aans=0; 
	for(int i=0;i<to[x].size();i++){
		if(to[x][i]==d1)continue;
		if(to[x][i]==d2)continue;
		if(to[x][i]==fa[x])continue;
		aans=max(aans,find2(to[x][i],0,0));
	}
	aans++;
	if(aans>d)ans++;
	return aans;
}
bool chk(int x){
	int jj=1;
	int l=1,r=n;
	d=x;ans=0;cnt=0;int maxx=0;
	for(int i=u;i!=p1.first;i=fa[i]){
		if(to[fa[i]].size()>2){
			find2(fa[i],i,fa[fa[i]]);
			a[++cnt]=jj+1;
			if(cnt==1&&a[cnt]>d)maxx=max(maxx,a[cnt]-d-1);
			else maxx=max(maxx,a[cnt]-a[cnt-1]); 
		}
		jj++;
	}
	if(a[cnt]<jj-d)maxx=max(maxx,jj-d-a[cnt]);
	if(ans+n-2*d-min(maxx,2*d)<=k)return true;
	else return false;
}
void solve(){
	cin>>n>>k;cnt=0;
	for(int i=1;i<=n;i++)to[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int i=1;i<=n;i++)fa[i]=0;
	p1=find1(1);
	for(int i=1;i<=n;i++)fa[i]=0;
	p2=find1(p1.first);
	u=p2.first;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(chk(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}cout<<l<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
