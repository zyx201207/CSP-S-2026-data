#include<bits/stdc++.h>
using namespace std;
struct aa{
	int id,t;
}a[1005][1005];
int n,m,c,d,q,w[10005],dian[1005][1005],minn[1005][1005],ui[10005],vi[10005],un=0,vn=0,map[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(minn,0x3f,sizeof minn);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].id>>a[i][j].t;
			
			for(int o=1;o<=n;o++){
				if(o!=i){
					if(dian[o][a[i][j].id])	{
						minn[o][i]=minn[i][o]=min(a[i][j].t+a[o][dian[o][a[i][j].id]].t,minn[o][i]);
						
					}																
				}
				else{
					minn[o][i]=minn[i][o]=0;
				}
			}
			dian[i][a[i][j].id]=j;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				if(i==o||o==j||j==i)	continue;
				if(minn[i][o]+minn[i][j]<minn[o][j])	minn[o][j]=minn[i][o]+minn[i][j];
			}
		}
	}

	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		for(int j=1;j<=n;j++){
			
			if(dian[j][u])	ui[un++]=j;
			if(dian[j][v])	vi[vn++]=j;	
			
		}
		int minx=0x3f,miny=0x3f;
		for(int j=0;j<un;j++){
			for(int o=0;o<vn;o++){
				if(minx+miny>=minn[ui[j]][vi[o]]+a[ui[j]][dian[ui[j]][u]].t+a[vi[o]][dian[vi[o]][v]].t){
					minx=minn[ui[j]][vi[o]];
					miny=a[ui[j]][dian[ui[j]][u]].t+a[vi[o]][dian[vi[o]][v]].t;
				}
				
			}
		}
		cout<<minx+miny+w[u]+w[v]<<endl;
	}
	return 0;
} 
