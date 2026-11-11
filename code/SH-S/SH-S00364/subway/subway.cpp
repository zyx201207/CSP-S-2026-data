#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int s[500010] = {};
int c,n,m,d,p;
int t[500010] = {};
int v[500010][5] = {}; 
int u[500010][500010] = {};

int main(){
	freopen("subway.in","r",stdin);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;++i){
		cin>>s[i];
	}
	for(int i=1;i<=n;++i){
		int a;
		cin>>a;
		for(int j=1;j<=a;++j){
			cin>>v[j][1];
			cin>>u[j][v[j][1]];
		}
		
	}
	for(int i=1;i<=p;++i){
		int x,y;
		cin>>x>>y;
		int sum = 0;
		for(int j=1;j<=n;++j){
			sum+=s[x]+s[y];
			for(int k=1;k<=m;++k){
				if((u[j][k]>0)){
					for(int g=k;g<=m;++g){
						if(u[g][k]>0){
							sum+=u[j][k]+u[g][k];
						}
					}
				}
			}
			
		}
		cout<<sum<<endl;
	}
	return 0;
	freopen("subway.out","w",stdout);
}
