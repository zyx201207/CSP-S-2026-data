#include<bits/stdc++.h>
using namespace std;
struct S{
	int to,time;
};
vector <S>a[500505];
bool k[500005];
long long ans[500005];
int c,n,m,l,q;
void add(int x){
	k[x]=1;
	for(int i=0;i<a[x].size();i++){
		if(!k[a[x][i].to]) ans[a[x][i].to]=ans[a[x][i].to]==-1?ans[x]+a[x][i].time:min(ans[a[x][i].to],ans[x]+a[x][i].time);
	}
}
long long least(int st,int en){
	memset(k,0,sizeof(k));
	memset(ans,-1,sizeof(ans));
	ans[st]=0;
	add(st);
	while(1){
		int address;
		long long minn=5e14;
		for(int i=1;i<=m+n;i++){
			if(ans[i]!=-1&&ans[i]<minn&&!k[i]) minn=ans[i],address=i;
		}
		if(address==en) return minn;
		add(address);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
    cin>>c>>n>>m>>l>>q;
    int b[500005];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
    	int k;
    	cin>>k;
    	for(int j=1;j<=k;j++){
    		int x,y;
    		cin>>x>>y;
    		S g;
    		g.time=y,g.to=m+i;
    		a[x].push_back(g);
    		g.to=x;
    		a[m+i].push_back(g);
		}
	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		cout<<1ll*(b[st]+b[en]+least(st,en))<<endl;
	}
	return 0;
}