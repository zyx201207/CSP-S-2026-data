#include<bits/stdc++.h>
using namespace std;
const int E=100000008;
int C,N,M,D,Q,w[500005],k[500005];
int a[500005][100],t[500005][100];
int u,v,ans=0,s0=0;
int s[500005],f[500005];
bool vis[500005];
struct EDGE{
	int u,v,l;
}e[500005];
//vector<EDGE> e;
int head[500005],nxt[500005];

int top=0;

void add(int u,int v,int l){//´Óuµ½v
	top++;
	nxt[top]=head[u];
	head[u]=top;
	e[top].u=u;
	e[top].v=v;
	e[top].l=l;
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>N>>M>>D>>Q;
	for(int i=1;i<=M;i++){
		cin>>w[i];
	}
	for(int i=1;i<=N;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int xx=1;xx<k[i];xx++){
			for(int yy=xx+1;yy<=k[i];yy++){
				int ll=0;
				//u=a[i][xx]
				//v=a[i][yy]
				add(a[i][xx],a[i][yy],t[i][xx]+t[i][yy]);
				add(a[i][yy],a[i][xx],t[i][xx]+t[i][yy]);
			}
		}
//		cout<<"(";
	}
	
	
//	for(int i=1;i<=M;i++){
//		for(int j=head[i];j;j=nxt[j]){
//			cout<<e[j].u<<" "<<e[j].v<<" "<<e[j].l<<" "<<endl;
//		}
//	}
//	cout<<endl;
//	for(int i=1;i<=top;i++){
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].l<<" "<<endl;
//	}
//	
	while(Q--){
		ans=0;
		s0=0;
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		cin>>u>>v;
//		cout<<"||"<<u<<" "<<v<<":";
//		cout<<endl<<endl;
		ans+=w[u];
		ans+=w[v];
		s0++;
		s[s0]=u;
		vis[u]=true;
		while(!vis[v]){
//			cout<<"!";
			int minn=0x7fffffff,minx;
			
			for(int i=1;i<=s0;i++){
//				cout<<"@";
				for(int j=head[s[i]];j;j=nxt[j]){
//					cout<<"#";
					if(f[s[i]]+e[j].l<minn&&(!vis[e[j].v])&&(e[j].l!=0)){
//						cout<<"!!!"<<" "<<s[i]<<" "<<e[j].v<<" "<<e[j].l<<endl;
						minn=f[s[i]]+e[j].l;
						minx=j;
					}
				}
			}
//			cout<<e[minx].v<<endl;
			s[++s0]=e[minx].v;
			vis[e[minx].v]=true;
			f[e[minx].v]=minn;
		}
		cout<<f[v]+ans<<endl;
//		for(int i=1;i<=M;i++){
//			cout<<f[i]<<" ";
//		}
//		cout<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

/*
32
17
*/
