#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef pair<long long,int> PII
const int N=5e5+10,M=510;
int num,n,m,d,q,w[M];
int t[N][M];
struct edge{
	int to,id;
};
vector<edge> a[M];
int idx[M];
ll dis[M];
bool f[M];
bool lijie[M];
int yaojia;
//priority_queue<PII, vector<PII>, greater<PII> > q;

void dijstra(int s){
	memset(dis,0x3f,sizeof(dis));
	
	bool lijieflag=1;
	dis[s]=0;
	for(int i=1;i<=m;i++){
		int mi=0;
		for(int j=1;j<=m;j++)
			if(!f[j] && dis[j]<=dis[mi]) mi=j;
		//cout<<mi<<' ';
		
		f[mi]=1;
		//cout<<mi<<':';
		if(lijie[mi] && lijieflag) {
			yaojia=idx[mi];
			lijieflag=0;
		}
		for(int j=0;j<a[mi].size();j++){
			int to=a[mi][j].to, id=a[mi][j].id;
			//cout<<to<<' ';
			if(mi==s) {
				//cout<<1;
				if(dis[mi]<dis[to]) {
				    dis[to]=dis[mi];
				    idx[to]=id;
				    lijie[to]=1;
			    }
			}else { 
			    if(id==idx[mi] && dis[mi]<dis[to]){
			    	//cout<<2;
			    	dis[to]=dis[mi];
				    idx[to]=id;
				    //cout<<dis[to];
				} else {
					//cout<<3;
					ll l=t[idx[mi]][mi]+t[id][mi];
					//if(to==3) cout<<l;
					if(dis[mi]+l<dis[to]){
						dis[to]=dis[mi]+l;
				        idx[to]=id;
					}
				}
			} 
			//ut<<dis[to]<<' ';
		}
		//cout<<dis[s];
		//cout<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>num>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		
		int from;
		cin>>from;
		cin>>t[i][from];
		for(int j=2;j<=k;j++){
			int to;
			cin>>to;
			cin>>t[i][to];
			a[from].push_back({to,i});
			from=to;
		}
	}
	
	
	/*for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j].to<<" ";
		}
		cout<<'\n';
	}*/
	dijstra(1);
	//for(int i=1;i<=m;i++) cout<<dis[i]<<' ';
	//cout<<endl;
	while(q--){
		int s,e;
		cin>>s>>e;
		yaojia=0;
		dijstra(s);
		cout<<w[s]+w[e]+dis[e]+t[yaojia][s]+t[idx[e]][e]<<'\n';
		//for(int i=1;i<=m;i++) cout<<dis[i]<<' ';
		//cout<<endl;
	}
	return 0;
}
