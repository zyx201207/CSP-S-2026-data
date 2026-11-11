#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int>w;
struct I{
	int node;
	int walk;
};
struct II{
	int go,out,total,inid,outid;
};
vector<vector<I>>inn;
const int inf=1e9;
vector<vector<II>>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+1);
	mp.resize(m+1,vector<II>(m+1,{inf,inf,inf,-1}));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	inn.push_back({});
	int k,tmp1;
	for(int i=1;i<=n;i++){
		inn.push_back({});
		inn[i].push_back({-1,-1});
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>tmp1;
			if(j%2){
				inn[i].push_back({tmp1,0});
			}else{
				inn[i][j/2].walk=tmp1;
			}
		}
	}
	//build
	for(int i=1;i<=n;i++){
		for(int j=2;j<inn[i].size();j++){
			mp[inn[i][j-1].node][inn[i][j].node]={inn[i][j-1].walk,inn[i][j].walk,inn[i][j].walk+inn[i][j-1].walk,i,i};
			mp[inn[i][j].node][inn[i][j-1].node]={inn[i][j].walk,inn[i][j-1].walk,inn[i][j].walk+inn[i][j-1].walk,i,i};
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i==k||j==k||i==j||mp[i][k].total==inf||mp[k][j].total==inf)continue;
				bool is=0;
				if(mp[1][6].total!=11){
					is=1;
				}
				if(mp[i][k].outid==mp[k][j].inid){
					if(mp[i][k].total-mp[i][k].out+mp[k][j].total-mp[k][j].go<mp[i][j].total){
						mp[i][j].total=mp[i][k].total-mp[i][k].out+mp[k][j].total-mp[k][j].go;
						mp[i][j].go=mp[i][k].go;
						mp[i][j].out=mp[k][j].out;
						mp[i][j].outid=mp[k][j].outid;
						mp[i][j].inid=mp[i][k].inid;					
						if(mp[1][6].total==11 &&is){
							cout<<mp[i][k].total<<" "<<k<<" "<<mp[k][j].total<<" "<<i<<" "<<j<<" "<<"\n";
						}
					}
					
				}else{
					if(mp[i][k].total+mp[k][j].total<mp[i][j].total){
						mp[i][j].total=mp[i][k].total+mp[k][j].total;
						mp[i][j].go=mp[i][k].go;
						mp[i][j].out=mp[k][j].out;
						mp[i][j].outid=mp[k][j].outid;
						mp[i][j].inid=mp[i][k].inid;	
						if(mp[1][6].total==11 &&is){
							cout<<mp[i][k].total<<" "<<k<<" "<<mp[k][j].total<<" "<<i<<" "<<j<<" "<<"\n";
						}
					}
					
				}
				swap(i,j);
				
				if(mp[i][k].outid==mp[k][j].inid){
					if(mp[i][k].total-mp[i][k].out+mp[k][j].total-mp[k][j].go<mp[i][j].total){
						mp[i][j].total=mp[i][k].total-mp[i][k].out+mp[k][j].total-mp[k][j].go;
						mp[i][j].go=mp[i][k].go;
						mp[i][j].out=mp[k][j].out;
						mp[i][j].outid=mp[k][j].outid;
						mp[i][j].inid=mp[i][k].inid;					
						if(mp[1][6].total==11 &&is){
							cout<<mp[i][k].total<<" "<<k<<" "<<mp[k][j].total<<" "<<i<<" "<<j<<" "<<"\n";
						}
					}
					
				}else{
					if(mp[i][k].total+mp[k][j].total<mp[i][j].total){
						mp[i][j].total=mp[i][k].total+mp[k][j].total;
						mp[i][j].go=mp[i][k].go;
						mp[i][j].out=mp[k][j].out;
						mp[i][j].outid=mp[k][j].outid;
						mp[i][j].inid=mp[i][k].inid;	
						if(mp[1][6].total==11 &&is){
							cout<<mp[i][k].total<<" "<<k<<" "<<mp[k][j].total<<" "<<i<<" "<<j<<" "<<"\n";
						}
					}
					
				}
				swap(i,j);
				//if(i==1 && j==6){
				//	cout<<mp[1][k].total<<" "<<k<<" "<<mp[k][6].total<<" "<<mp[1][6].total<<"\n";
				//}
				
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<mp[x][y].total+w[x]+w[y]<<"\n";
	}
	return 0;
}