#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct r{
	int road;
	long long v;
};
r rr;
struct x{
	int u;
	long long v;
};
x xx;
vector<r>station[500050];
vector<x>subway[505];
vector<long long>x[550];

long long ch_way[505][505];
long long w[500050];
int st_c[100010][25];
long long st_v[100010][25];
int rec[10000010];

void dij(int g){
	long long juli[505];
	bool inr[505];
	for(int i=1;i<=n;i++)inr[i]=0;
	for(int i=1;i<=n;i++)juli[i]=10000000000;
	inr[g]=1;
	juli[g]=0;
	priority_queue< 
	pair< int , pair <int,int> >,
	vector< pair< int , pair <int,int> > >,
	greater< pair< int , pair <int,int> > >
	>  bian;//代价，出点，入点 
	//while(!bian.empty())bian.pop();
	int nown=g;
	int jsq=1;
	for(int ii=1;ii<n;ii++){
		for(int i=0;i<subway[nown].size();i++){
			bian.push( { subway[nown][i].v , {nown,subway[nown][i].u} } );	
		}
		while(!bian.empty()){
			if(inr[bian.top().second.second]==1)bian.pop();
			else{
				juli[bian.top().second.second]=juli[bian.top().second.first]+bian.top().first;
				nown=bian.top().second.second;
				inr[bian.top().second.second]=1;
				jsq++;
				if(jsq==n){
					for(int j=1;j<=n;j++){
						ch_way[g][j]=juli[j];
						ch_way[j][g]=juli[j];
					}
					return;
				}	
				bian.pop();
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ch_way[i][j]=5e9;
	for(int i=1;i<=n;i++){
		int k,a,t;//a表示地铁站序数，t表示站台到站厅时间 
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			rec[a]++;
			int q=rec[a];
			st_c[a][q]=i;
			st_v[a][q]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=rec[i];j++){
			for(int k=1;k<=rec[i];k++){
				ch_way[st_c[i][j]][st_c[i][k]]=min(ch_way[st_c[i][j]][st_c[i][k]],st_v[i][j]+st_v[i][k]);
			}
		}
	}
	

	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(ch_way[i][j]<5e9){
				xx.u=j;
				xx.v=ch_way[i][j];
				subway[i].push_back(xx);
			}
		}
	}
	for(int zz=n;zz>=1;zz--)dij(zz);
	
	for(int i=1;i<=q;i++){
		int chufa,daoda;
		cin>>chufa>>daoda;
		long long minn=9e12;
		for(int j=1;j<=rec[chufa];j++){
			for(int jj=1;jj<=rec[daoda];jj++){
				minn=min(minn,ch_way[st_c[chufa][j]][st_c[daoda][jj]]+w[chufa]+w[daoda]+st_v[chufa][j]+st_v[daoda][jj]);
			}
		}
		cout<<minn<<"\n";
	}
	return 0;
}
