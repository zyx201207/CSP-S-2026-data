#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,aq,w[505],k,f,r,dis[505][505],u,v,ans,nowans;
map<int,int> fty[500005],ytf[500005];
vector<pair<int,int> > y[505];
queue<int> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c>>n>>m>>d>>aq;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> k;
		if (k==1){
			cin >> f>>r;
			i--;n--;
			continue;
		}
		for (int j=1;j<=k;j++){
			cin >> f>>r;
			for (auto now:fty[f]){
				y[now.first].push_back({i,r+now.second});
			}
			fty[f][i]=r;
			ytf[i][f]=r;
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for (int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	q.push(1);
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for (auto now:y[i]){
			if (now.second<dis[i][now.first]){
				dis[i][now.first]=now.second;
				dis[now.first][i]=now.second;
				q.push(now.first);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				if (i!=j&&j!=k&&i!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	for (int i=1;i<=aq;i++){
		cin >> u>>v;
		ans=0x3f3f3f3f;
		for (auto uy:fty[u]){
			for (auto vy:fty[v]){
				ans=min(ans,dis[uy.first][vy.first]+uy.second+vy.second);
			}
		}
		cout << ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int c,n,m,d,aq,w[505],k,f,r,u,v,ans,len,pre[505],fa[505],bz[505][20],dep[505],cnt,nowd,gf,nu,nv,uu,vv,dis[505][505],nowans;
//map<int,int> fty[500005],ytf[500005];
//bool vis[505];
//vector<pair<int,int> > zy[505];
//struct rd{
//	int fro,to,num;
//} nowrd;
//rd y[250005];
//bool cmp(rd a,rd b){
//	return a.num<b.num;
//}
//int build(int x){
//	for (auto i:zy[x]){
//		if (vis[i.first]){
//			continue;
//		}
//		fa[i.first]=x;
//		vis[i.first]=1;
//		dep[i.first]=dep[x]+1;
//		bz[i.first][0]=x;
//		dis[x][i.first]=dis[i.first][x]=i.second;
//		pre[x]+=build(i.first)+i.second;
//	}
//	return pre[x];
//}
//queue<int> q;
//int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin >> c>>n>>m>>d>>aq;
//	for (int i=1;i<=m;i++){
//		cin >> w[i];
//	}
//	for (int i=1;i<=n;i++){
//		cin >> k;
//		if (k==1){
//			cin >> f>>r;
//			i--;n--;
//			continue;
//		}
//		for (int j=1;j<=k;j++){
//			cin >> f>>r;
//			for (auto now:fty[f]){
//				len++;
//				nowrd.fro=i,nowrd.to=now.first,nowrd.num=r+now.second;
//				y[len]=nowrd;
//			}
//			fty[f][i]=r;
//			ytf[i][f]=r;
//		}
//	}
//	sort(y+1,y+len+1,cmp);
//	for (int i=1;i<=len;i++){
//		if (!(vis[y[i].fro]&&vis[y[i].to])){
//			zy[y[i].fro].push_back({y[i].to,y[i].num});
//			zy[y[i].to].push_back({y[i].fro,y[i].num});
//			vis[y[i].fro]=vis[y[i].to]=1;
//		}
//	}
//	for (int i=1;i<=n;i++){
//		fa[i]=i;
//	}
//	memset(vis,0,sizeof(vis));
//	vis[1]=1;
//	bz[1][0]=1;
//	dep[1]=1;
//	build(1);
//	for (int i=1;i<=19;i++){
//		bz[1][i]=0;
//	}
//	q.push(1);
//	memset(vis,0,sizeof(vis));
//	vis[1]=1;
//	while(!q.empty()){
//		int aaa=q.front();
//		q.pop();
//		if (aaa!=1){
//			for (int i=1;i<=19;i++){
//				bz[aaa][i]=bz[bz[aaa][i-1]][i-1];
//			}
//		}
//		for (auto i:zy[aaa]){
//			if (!vis[i.first]){
//				q.push(i.first);
//				vis[i.first]=1;
//			}
//		}
//	}
//	for (int i=1;i<=aq;i++){
//		cin >> u>>v;
//		ans=0x3f3f3f3f;
//		for (auto uy:fty[u]){
//			for (auto vy:fty[v]){
//				uu=uy.first;
//				vv=vy.first;
//				if (dep[uu]<dep[vv]){
//					swap(uu,vv);
//				}
//				nu=uu,nv=vv;
//				while(dep[nu]!=dep[nv]){
//					nowd=dep[nu]-dep[nv];
//					cnt=0;
//					while(nowd){
//						cnt++;
//						nowd>>=1;
//					}	
//					nu=bz[nu][nowd];
//				}
//				if (nu==nv){
//					gf=nu;
//					nowans=0;
//					nu=uu;
//					while(nu!=vv){
//						nowans+=dis[nu][fa[nu]];
//						nu=fa[nu];
//					}
//					nowans+=ytf[uy.first][u]+ytf[vy.first][v];
//				}
//				else{
//					cnt=19;
//					for (int i=1;i<=19;i++){ 
//						while(bz[nu][cnt]==bz[nv][cnt]){
//							cnt--;
//						}
//						nu=bz[nu][cnt];
//						nv=bz[nv][cnt];
//					}
//					gf=nu;
//					nowans=pre[gf]-pre[u]-pre[v]+ytf[uy.first][u]+ytf[vy.first][v];
//				}
//				ans=min(ans,nowans);
//			}
//		}
//		cout << ans+w[u]+w[v]<<"\n";
//	}
//	return 0;
//}


