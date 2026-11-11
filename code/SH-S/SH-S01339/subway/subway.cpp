#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5e5+5;
const int MAXN=505;

int c,d,q;
int m,w[MAXM];
int n,k[MAXN];
struct node1{
	int stationid;
	int costtime;
};
struct node2{
	int routeid;
	int costtime;
};
vector<node1> pass[MAXN];//1-based
vector<node2> access[MAXM];//0-based

int minct[MAXN][MAXN];
void solveminct(){
	memset(minct,0x3f,sizeof(minct));
	for(int i=1;i<=n;i++) minct[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int station=pass[i][j].stationid;
			int ct1=pass[i][j].costtime;
			
			const vector<node2> &saccess=access[station];
			int sasize=saccess.size();
			for(int toid=0;toid<sasize;toid++){
				int toroute=saccess[toid].routeid;
				int ct2=saccess[toid].costtime;
				
				minct[i][toroute]=min(minct[i][toroute],ct1+ct2);
				minct[toroute][i]=min(minct[toroute][i],ct1+ct2);
			}
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				minct[i][j]=min(minct[i][j],minct[i][k]+minct[k][j]);
			}
		}
	}
}

int solve(int u,int v){
	if(u==v) return 0;
	int ans=1e18;
	
	const vector<node2> &sac1=access[u];
	const vector<node2> &sac2=access[v];
	int ssize1=sac1.size();
	int ssize2=sac2.size();
	for(int i=0;i<ssize1;i++){
		int rid1=sac1[i].routeid;
		int costtime1=sac1[i].costtime;
		for(int j=0;j<ssize2;j++){
			int rid2=sac2[j].routeid;
			int innercost=minct[rid1][rid2];
			int costtime2=sac2[j].costtime;
			int tottime=costtime1+innercost+costtime2;
			
			ans=min(ans,tottime);
		}
	}
	
	return ans+w[u]+w[v];
} 

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		pass[i].resize(k[i]+1);
		node2 buf;
		for(int j=1;j<=k[i];j++){
			int sid,costt;
			cin>>sid>>costt;
			pass[i][j].stationid=sid;
			pass[i][j].costtime=costt;
			buf.routeid=i;
			buf.costtime=costt;
			access[sid].push_back(buf);
		}
	}
	
	solveminct();
	floyd();
	
	for(int i=1;i<=q;i++){
		int uu,vv;
		cin>>uu>>vv;
		cout<<solve(uu,vv)<<endl;
	}
	return 0;
} 
