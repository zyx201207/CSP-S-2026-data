#include <bits/stdc++.h>
using namespace std;
struct zx{
	int xl;
	int zd;
	int num;
};
int w[500010];
vector<pair<int,int>> xl[510];
vector<pair<int,int>> zdx[500010];
int visxl[510];
int viszd[500010];
void solve(int a,int b){
	int mn=1e9;
	queue<zx> q;
	zx tmp;
	tmp.xl=0;
	tmp.zd=a;
	tmp.num=w[a];
	q.push(tmp);
	viszd[a]=1;
	while(!q.empty()){
		zx p=q.front();
		q.pop();
		if(p.zd==b){
			if(mn>p.num+w[b]){
				mn=p.num+w[b]; 
			}
			continue;
		}
		if(p.zd==0){
			for(int i=0;i<xl[p.xl].size();i++){
				
				if(viszd[xl[p.xl][i].first]){
					continue;
				}
				viszd[xl[p.xl][i].first]=1;
				zx t;
				t.num=xl[p.xl][i].second+p.num;
				t.xl=0;
				t.zd=xl[p.xl][i].first;
				q.push(t);
			}
		}else{
			for(int i=0;i<zdx[p.zd].size();i++){
				
				if(visxl[zdx[p.zd][i].first]){
					continue;
				}
				visxl[zdx[p.zd][i].first]=1;
				zx t;
				t.num=zdx[p.zd][i].second+p.num;
				t.xl=zdx[p.zd][i].first;
				t.zd=0;
				q.push(t);
			}
		}
	}
	cout<<mn<<endl;
	return ;
}
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int a,t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			xl[i].push_back({a,t});
			zdx[a].push_back({i,t});
		}
	}
	int a,b;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		memset(viszd,0,sizeof(viszd));
		memset(visxl,0,sizeof(visxl));
		solve(a,b);
	}
	return 0;
}
