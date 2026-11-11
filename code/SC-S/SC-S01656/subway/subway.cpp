#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct nt{
	int m,t;
};
int w[500001];
long long f[500001];
vector<nt> xian[500501];
bool fl[500001];

nt maken(int m,int t){
	nt o;
	o.m=m,o.t=t;
	return o;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(fl,0,sizeof(fl));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	int k,a,t;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
			xian[i].push_back(maken(n+a,t));
			xian[n+a].push_back(maken(i,t));
		}
	}
	int x,y;
	for(int i=0;i<q;i++){
		memset(f,127,sizeof(f));
		cin>>x>>y;
		f[x+n]=0;
		queue<int> q;
		q.push((x+n));
		while(!q.empty()){
			int o=q.front();
			q.pop();
			for(int i=0;i<xian[o].size();i++){
				nt oo=xian[o][i];
				if(f[oo.m]>f[o]+oo.t) {
					q.push(oo.m);
					f[oo.m]=f[o]+oo.t;
				}
			}
		}
		cout<<f[y+n]+w[x]+w[y]<<endl;
	}
	return 0;
} 