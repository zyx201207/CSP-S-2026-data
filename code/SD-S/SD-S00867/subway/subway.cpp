#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
int w[500010];
vector<pair<int,int> > a[500010];
int xx,yy,maxx;
bool f[500010];
void dfs(int xb,int s){
	if(f[xb]) return ;
	if(xb==yy){
		maxx=min(maxx,s);
		return ;
	}
	f[xb]=1;
	for(int i=0;i<a[xb].size();i++){
		dfs(a[xb][i].first,s+a[xb][i].second);
	}
	f[xb]=0;
}
pair<int ,int> hh[101000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int nn;
		cin>>nn;
		for(int j=1;j<=nn;j++){
			cin>>hh[j].first>>hh[j].second;
		}
		for(int j=1;j<=nn;j++){
			for(int p=1;p<j;p++){
				pair<int,int>jj,kk;
	    	jj.first=hh[p].first;
	    kk.first=hh[j].first;
	    jj.second=kk.second=hh[j].second+hh[p].second;
		a[kk.first].push_back(jj);
		a[jj.first].push_back(kk);
			}
		}
//		int aa,bb,cc,dd;
//		cin>>aa>>bb>>cc>>dd;
		
//		jj.first=cc;
//	    kk.first=aa;
//	    jj.second=kk.second=bb+dd;
//		a[aa].push_back(jj);
//		a[cc].push_back(kk);
	}
	for(int i=1;i<=	q;i++){		
	for(int j=1;j<=n;j++){
		f[j]=0;
	}
	maxx=INT_MAX;
		cin>>xx>>yy;
		dfs(xx,0);
		cout<<maxx+w[xx]+w[yy]<<'\n';
	}
	return 0;
}
/*
如今一个人听歌时总会觉得失落，幻听你在我的耳边轻轻诉说，夜有多温柔，你有多爱我。
如今一个人听歌时总会觉得难过，爱意不在这里我却还没走脱，歌单里的歌，随过往流动。



*/
