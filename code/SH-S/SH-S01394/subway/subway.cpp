#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long c,n,m,d,q;
long long w[500005];
bool v[505];

struct lineentry{
	long long linenum;
	long long dist;
};

vector<lineentry> avail_lines[500005];

struct interchange{
	long long towards;
	long long dist;
};

struct exchange{
	long long from;
	long long towards;
	long long dist;
};

operator <(exchange a,exchange b){
	return a.dist>b.dist;
}

long long minchangecost[505][505];
vector<interchange> avail_change[505];
priority_queue<exchange> changes;

long long exchangecost[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(long long i=1;i<=m;i++){
		cin >> w[i];
	}
	for(long long i=1;i<=n;i++){
		long long temp;
		cin >> temp;
		for(long long j=1;j<=temp;j++){
			long long a,b;
			cin >> a >> b;
			avail_lines[a].push_back({i,b});
		}
	}
	/*for(int i=1;i<=m;i++){
		cout << avail_lines[i].size() << endl;
		for(auto x:avail_lines[i]){
			cout << x.linenum <<' '<<x.dist <<endl;
		}
	}*/
	//avail_lines test
	for(long long i=1;i<=m;i++){
		long long gunmu=avail_lines[i].size();
		for(long long j=0;j<gunmu-1;j++){
			for(long long k=j+1;k<=gunmu-1;k++){
				if(minchangecost[avail_lines[i][j].linenum][avail_lines[i][k].linenum]==0){
					minchangecost[avail_lines[i][j].linenum][avail_lines[i][k].linenum]=avail_lines[i][j].dist+avail_lines[i][k].dist;
					minchangecost[avail_lines[i][k].linenum][avail_lines[i][j].linenum]=avail_lines[i][j].dist+avail_lines[i][k].dist;
				}else{
					if(minchangecost[avail_lines[i][j].linenum][avail_lines[i][k].linenum]>avail_lines[i][j].dist+avail_lines[i][k].dist){
						minchangecost[avail_lines[i][j].linenum][avail_lines[i][k].linenum]=avail_lines[i][j].dist+avail_lines[i][k].dist;
						minchangecost[avail_lines[i][k].linenum][avail_lines[i][j].linenum]=avail_lines[i][j].dist+avail_lines[i][k].dist;
					}
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << minchangecost[i][j] << ' ';
		}
		cout << endl;
	}*/
	// min exchange cost test
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(minchangecost[i][j]){
				avail_change[i].push_back({j,minchangecost[i][j]});
			}
		}
	}
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			v[j]=false;
		}
		exchangecost[i][i]=0;
		v[i]=true;
		for(auto x:avail_change[i]){
			changes.push({i,x.towards,x.dist});
		}
		while(!changes.empty()){
			exchange x=changes.top();
			changes.pop();
			if(v[x.towards])continue;
			exchangecost[i][x.towards]=x.dist;
			v[x.towards]=true;
			for(auto y:avail_change[x.towards]){
				changes.push({x.towards,y.towards,y.dist+exchangecost[i][x.towards]});
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << exchangecost[i][j] << ' ';
		}
		cout << endl;
	}*/
	for(long long i=1;i<=q;i++){
		long long a,b;
		cin >> a >> b;
		long long ans=2000000000;
		//cout << avail_lines[a].size() << ' ' << avail_lines[b].size() << ' ';
		for(auto x:avail_lines[a]){
			for(auto y:avail_lines[b]){
				//cout << exchangecost[x.linenum][y.linenum] << ' ' << x.dist << ' ' << y.dist << endl;
				if(ans>exchangecost[x.linenum][y.linenum]+x.dist+y.dist){
					ans=exchangecost[x.linenum][y.linenum]+x.dist+y.dist;
				}
			}
		}
		cout << ans+w[a]+w[b] << endl;
	}
	
	return 0;
}
