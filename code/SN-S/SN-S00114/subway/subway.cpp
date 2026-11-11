#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long f[505][505],minx=1000000000000000;
vector<pair<int,int> > vc[2005];
vector<pair<int,int> > ve[2005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int z=1; z<=m; z++){
		cin>>w[z];
		vc[500+z].push_back({z,w[z]});
		vc[z].push_back({500+z,w[z]});
	}
	for(int z=1; z<=n; z++){
		int k;
		cin>>k;
		for(int x=1; x<=k; x++){
			int a,t;
			cin>>a>>t;
			vc[1000+z].push_back({a,t});
			vc[a].push_back({1000+z,t});
			//cout<<"llllppp"<<a<<" "<<t<<endl;
		}
		//cout<<"aaaaaaaaaaaa"<<z<<" "<<k<<endl;
	}
	for(int z=0; z<=500; z++){
		for(int x=0; x<=500; x++){
			f[z][x]=1000000000000000;
			if(z==x)f[z][x]=0;
		}
	}
	
	for(int z=1; z<=m; z++){
		if(vc[z].size()>2){
			for(int x=1; x<vc[z].size(); x++){
				for(int c=x+1; c<vc[z].size(); c++){
					
					ve[vc[z][x].first].push_back({vc[z][c].first,(vc[z][x].second+vc[z][c].first)});
				
					ve[vc[z][c].first].push_back({vc[z][x].first,vc[z][x].second+vc[z][c].second});
				
					f[vc[z][x].first-1000][vc[z][c].first-1000]=min((long long)(f[vc[z][x].first-1000][vc[z][c].first-1000]),
					(long long)(vc[z][x].second+vc[z][c].second));
					
					f[vc[z][c].first-1000][vc[z][x].first-1000]=min((long long)(f[vc[z][c].first-1000][vc[z][x].first-1000]),
					(long long)(vc[z][x].second+vc[z][c].second));
			
				}
			}
		}
	}
	
	for(int x=1001; x<=1000+n; x++){
		for(int z=1001; z<=1000+n; z++){
			//cerr<<f[x-1000][z-1000]<<" ";
			for(int c=1001; c<=1000+n; c++){
				f[z-1000][c-1000]=min(f[z-1000][c-1000],
				f[z-1000][x-1000]+f[x-1000][c-1000]);
			}
		}
	}
	for(int z=1; z<=q; z++){
		int xx,yy;
		minx=1000000000000000;
		cin>>xx>>yy;
		//cout<<xx<<" "<<yy<<endl;
		//cout<<vc[xx].size()<<" "<<vc[yy].size();
		for(int z=1; z<vc[xx].size(); z++){
			for(int x=1; x<vc[yy].size(); x++){
				minx=min(minx,f[vc[xx][z].first-1000][vc[yy][x].first-1000]+
				w[xx]+w[yy]+vc[xx][z].second+vc[yy][x].second);
				//cerr<<"11111111111"<<minx<<" "<<f[vc[xx][z].first-1000][vc[yy][x].first-1000]+
				//w[xx]+w[yy]+vc[xx][z].second+vc[yy][x].second<<endl;
			}
		}
		cout<<minx<<"\n";
	}
	return 0;
}
