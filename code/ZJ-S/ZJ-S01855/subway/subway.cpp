#include<bits/stdc++.h>
#define to ac
using namespace std;
const int N=1501;
const int M=2e4+502;
int c,n,m,d;

long long w[M];
long long len[N][N];


vector< int > q[M];
vector<long long>val[N];
bool vis[M];

//task2--------------------------------------------------------------
long long go(int x,int y){
	
	memset(vis,0,sizeof(vis));
	queue<int > pq;
	queue<int > va;
	
	vis[x]=1;
	pq.push(x);
	va.push(0);
	while( !pq.empty() ){
		int to=pq.front();
		int v=va.front();
		va.pop();
		pq.pop();
		if(to==y){
			return v;
		}
		
		
		//cout<<l<<" "<<to<<"\n";
		
		for( int j=0;j<q[to].size();j++ ){
			if( vis[ q[to][j] ]==0  ){
				pq.push( q[to][j] );
				va.push( v+1 );
				vis[ q[to][j] ]=1;
			}
		}
	}
	//cout<<"\n";
	return -1;
}

//-----------------------------------task1--------------------------------
void connect(int x,long long v,int y){
	q[x].push_back(y);
	q[y].push_back(x);
	val[x].push_back(v);
	val[y].push_back(v);
}


struct D{
	long long l;
	int to;
	friend bool operator<(D a,D b){
		return a.l>b.l;
	}
}dl;

priority_queue<D>pq;
void inn(long long l,int t){
	dl.l=l;
	dl.to=t;
	pq.push(dl);
	return;
}


void dij(int s){
	
	for(int i=1;i<=m+n;i++)vis[i]=0;
	//cout<<s<<":\n";
	len[s][s]=0;
	while( !pq.empty() )pq.pop();
	
	inn( 0ll,s );
	
	while( !pq.empty() ){
		long long l=pq.top().l;
		int to=pq.top().to;
		
		pq.pop();
		if( vis[to] )continue;
		vis[to]=1;
		
		//cout<<l<<" "<<to<<"\n";
		
		len[s][to]=l;
		for( int j=0;j<q[to].size();j++ ){
			long long nt= len[s][to]+val[to][j];
			if( ( vis[q[to][j]]==0 ) && (len[s][ q[to][j] ]>nt ) ){
				inn( nt , q[to][j] );
				len[s][ q[to][j] ]=nt;
			}
		}
	}
	//cout<<"\n";
	return;
}
//------------------------------------------------------------------------

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset( len , 0x3f,sizeof(len) );
	
	int ttt;
	cin>>c>>n>>m>>d>>ttt;
	
	
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	if( ( c>=12 )&&( c<=15 ) ){
		int a,h;
		long long t;
		for(int i=1;i<=n;i++){
			
			cin>>h;
			while(h--){
				cin>>a>>t;
				q[a].push_back(m+i);
				q[m+i].push_back(a);
			}
		}
		while(ttt--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+go(x,y)*t<<"\n";
		}
		
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int a,t,h;
		cin>>h;
		for(int j=1;j<=h;j++){
			cin>>a>>t;
			connect( a,t,m+i );
		}
	}
	for(int i=1;i<=m;i++)dij(i);
	
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)cout<<len[i][j]<<" ";
		cout<<"\n";
	}*/
	while(ttt--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+len[x][y]<<"\n";
	}
	return 0;
}
