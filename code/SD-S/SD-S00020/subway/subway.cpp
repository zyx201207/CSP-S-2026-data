#include<bits/stdc++.h>
#define int long long
using namespace std;
struct to{
	int v,w;
	to(const int a,const int b):v(a),w(b) {}
};
int f[505][505];
bitset<500005> of[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<map<int,int> > lt(n+1);
	//vector<vector<int> > g(n+1);
	vector<int> w(m+1,0);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			of[i][a]=true;
			lt[i][a]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				f[i][j]=0;
			}else{
				f[i][j]=4e16;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto ao:lt[i]){
			const int a=ao.first,b=ao.second;
			for(int j=i+1;j<=n;j++){
				if(of[j][a]){	
					int co=b+lt[j][a];
					f[i][j]=f[j][i]=min(f[i][j],co);
				}
			}
		}
	}//1.25e8
	for(int h=1;h<=n;h++){
		for(int i=1;i<=n;i++){
			if(i==h) continue;
			for(int j=1;j<=n;j++){
				if(h==j||i==j) continue;
				f[i][j]=min(f[i][j],f[i][h]+f[h][j]);
			}
		}
	}//1.25e8
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<endl;
			continue;
		}
		const int aw=w[x]+w[y];
		int an=1e17;
		set<int> so,sp,sop;
		for(int i=1;i<=n;i++){
			if(of[i][x]){
				so.insert(i);
				sop.insert(i);
			}
			if(of[i][y]){
				sp.insert(i);
				sop.insert(i);
			}
		}
		for(const int i:so){
			for(const int j:sp){
				an=min(an,lt[i][x]+lt[j][y]+f[i][j]);	
			}
		}
		cout<<an+aw<<endl;
	}//4e7
	return 0;
}

