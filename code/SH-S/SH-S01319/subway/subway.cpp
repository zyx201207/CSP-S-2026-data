#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005
int c,n,m,d,q,nu,dd,ee,x,y,qwe;
int w[MAXN];
struct way{
	int p;
	int t;
};
way ac;
vector<way>edge[MAXN];
vector<way>che[MAXN];
vector<int>sub[MAXN];
int vis[MAXN],viss[MAXN],ddd[MAXN],sa[MAXN],ha[MAXN];
void bfs(int hhh,int fl){
	for(int i:sub[hhh]){
		if(vis[i]==0){
			vis[i]=1;
			for(way j:edge[i]){
				if(viss[j.p]==0){
					qwe++;
					sa[qwe]=j.p;
					viss[j.p]=1;
					ha[qwe]=fl+1;
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
		if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			cin>>nu;
			int d1,e1,d2,e2;
			cin>>d1>>e1>>d2>>e2;
			ac.p=d2;
			ac.t=e1+e2;
			che[d1].push_back(ac);
			ac.p=d1;
			che[d2].push_back(ac);
		}
		while(q--){
			for(int i=1;i<=m;i++){
				ddd[i]=MAXN;
				vis[i]=0;
			}
			cin>>x>>y;
			ddd[x]=0;
			for(int i=1;i<=m;i++){
				int mm=MAXN,l;
				for(int j=1;j<=m;j++){
					if(mm>ddd[j]&&vis[j]==0){
						mm=ddd[j];
						l=j;
					}
				}
				if(l==y){
					cout<<ddd[l]+w[x]+w[y]<<endl;
					break;
				}
				vis[l]=1;
				for(way i:che[l]){
					ddd[i.p]=min(ddd[i.p],ddd[l]+i.t);
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>nu;
			for(int j=1;j<=nu;j++){
				cin>>dd>>ee;
				ac.p=dd;
				ac.t=ee;
				edge[i].push_back(ac);
				sub[dd].push_back(i);
			}
		}
		if(c>=12&&c<=19){
			while(q--){
				for(int i=1;i<=m;i++){
				ddd[i]=MAXN;
				vis[i]=0;
				viss[i]=0;
				}
				cin>>x>>y;
				qwe=1;
				sa[1]=x;
				viss[x]=1;
				ha[1]=0;
				for(int i=1;i<=m;i++){
	//				cout<<sa[i]<<" "<<ha[i]<<endl;
					if(sa[i]==y){
						cout<<ha[i]*2*ac.t+w[x]+w[y]<<endl;
						break;
					}
					bfs(sa[i],ha[i]);
				}
			}
		}
		else {
		while(q--){
			for(int i=1;i<=m;i++){
				ddd[i]=MAXN;
				vis[i]=0;
			}
			cin>>x>>y;
			ddd[x]=0;
			for(int i=1;i<=m;i++){
				int mm=MAXN,l;
				for(int j=1;j<=m;j++){
					if(mm>ddd[j]&&vis[j]==0){
						mm=ddd[j];
						l=j;
					}
				}
				if(l==y){
					cout<<ddd[l]+w[x]+w[y]<<endl;
					break;
				}
				vis[l]=1;
				for(int i:sub[l]){
					int qq;
					for(way j:edge[i]){
						if(j.p==l){
							qq=j.t;
							break;
						}
					}
					for(way j:edge[i])
					ddd[j.p]=min(ddd[j.p],ddd[l]+j.t+qq);
				}
			}
		}	
		}
	}
	return 0;	
} 
