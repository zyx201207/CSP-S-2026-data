#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int w[1010];
int cnt[1010];
int e[1010][1010];
vector<int> b[1010];
int t[1010];
int nox[1010];
map<pair<int,int>,int> edgenums;
long long dis[1010];
priority_queue<pair<long long,int> > qu;
bool vis[1010];
int cntt[500010];
int sub[520][500010];
int site[500010][30];
int k[520];
int ee[520][520];
priority_queue<pair<long long,int> > que;
int distwo[500010];
int vistwo[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	if(c>=12){
		int T;
		for(int i=1;i<=n;i++){
			k[i]=read();
			for(int j=1;j<=k[i];j++){
				int x=read();
				int t=read();
				T=t;
				sub[i][j]=x;
				cntt[x]++;
				site[x][cntt[x]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				int x=sub[i][j];
				if(cnt[x]>1){
					for(int l=1;l<=cnt[x];l++){
						for(int ll=1;ll<l;ll++){
							ee[site[x][l]][site[x][ll]]=T;
						}
					}
				}
			}
		}
		while(q--){
			memset(vis,0,sizeof(vis));
			while(!qu.empty()){
				qu.pop();
			}
			int xx,yy;
			xx=read(),yy=read();
			long long ans=LONG_LONG_MAX;
			for(int kkkk=1;kkkk<=cnt[xx];kkkk++){
				int x,y;
				x=site[xx][kkkk];
				for(int kkkkk=1;kkkkk<=cnt[yy];kkkkk++){
					y=site[yy][kkkkk];
					for(int i=1;i<=m;i++){
						dis[i]=LONG_LONG_MAX;
					}
					dis[x]=0;
					qu.push(make_pair(dis[x]*-1,x));
					while(!qu.empty()){
						int linshi=qu.top().second;
						for(int i=0;i<cnt[linshi];i++){
							int linshii=b[linshi][i];
							if(vis[linshii]==1){
								continue;
							}
							dis[linshii]=dis[linshi]+ee[linshi][linshii];
							qu.push(make_pair(dis[linshii]*-1,linshii));
							vis[linshii]=1;
						}
						qu.pop();
					}
					ans=min(ans,dis[y]+1ll*w[x]+1ll*w[y]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	else {
		for(int i=1;i<=n;i++){
			int k=read();
			for(int l=1;l<=k;l++){	
				nox[l]=read();
				t[l]=read();
				for(int j=1;j<l;j++){
					e[nox[l]][nox[j]]=t[l]+t[j];
//					b[nox[l]].push_back(nox[j]);
					e[nox[j]][nox[l]]=t[l]+t[j];
//					b[nox[j]].push_back(nox[l]);
					cnt[nox[l]]++;
					cnt[nox[j]]++;
				}
			}
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		while(!qu.empty()){
			qu.pop();
		}
		int x,y;
		x=read(),y=read();
//		if(c>=12){
//			x=site[x]
//		}
		for(int i=1;i<=m;i++){
			dis[i]=LONG_LONG_MAX;
		}
		dis[x]=0;
		qu.push(make_pair(dis[x]*-1,x));
		while(!qu.empty()){
			int linshi=qu.top().second;
			for(int i=0;i<cnt[linshi];i++){
				int linshii=b[linshi][i];
				if(vis[linshii]==1){
					continue;
				}
				dis[linshii]=dis[linshi]+e[linshi][linshii];
				qu.push(make_pair(dis[linshii]*-1,linshii));
				vis[linshii]=1;
			}
			qu.pop();
		}
		cout<<dis[y]+1ll*w[x]+1ll*w[y]<<'\n';
	}
}

