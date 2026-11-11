#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int time1[20050],lx[850][2000],lx1[850][2000],lxt[850][2000],lxt2[850][2000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>time1[i];
	}
	for(int i=1;i<=m;i++){
    	for(int j=1;j<=m;j++){
    		lxt[i][j]=0x3f3f3f3f;
    		lxt2[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
    	for(int j=1;j<=k;j++){
    		int e;
    		cin>>e>>lxt[j][i];//从j站厅走到i线站台的时间 
    		lx[i][e]=1;
		}
	}
	for(int i=1;i<=m;i++){
    	for(int j=1;j<=m;j++){
    		   for(int k=1;j<=n;j++){
    		        lxt2[i][j]=lxt[i][k]+lxt[j][k];
    		        lxt2[j][i]=lxt2[i][j];
    		        if(lx[k][i]==1&&lx[k][j]==1){
    		    	lx1[i][j]=1;
    		    	lx1[j][i]=1;
			    }
		   }
		}
	}	
	for(int l=1;l<=q;l++){
		int x,y;
		cin>>x>>y;
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				if(lx1[k][i]==0){
					continue;
				}
			    for(int j=1;j<=m;j++){
			    	if(lx1[k][j]==0){
				    	continue;
				    }
				    lxt2[i][j]=min(lxt2[i][j],lxt2[i][k]+lxt2[k][j]);
		        }
		    }
		}
		cout<<lxt2[x][y]+time1[x]+time1[y]<<endl;
	}
	return 0;
}
