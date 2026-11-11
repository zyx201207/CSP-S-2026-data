#include<bits/stdc++.h>
using namespace std;
int tin[20005];//,tai[50005]
int x[505][505];int tu[20005][20005];
int xian[20005][505];int nx[505][505][21];
int c,n,m,d,p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>tin[i];xian[i][0]=1;
		}
		
	int a,b;
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			x[i][0]=k;
			cin>>a>>b;
			x[i][j]=b;
			xian[i][xian[i][0]++]=a;
			}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)tu[i][j]=0x3f3f3f3f;
		tu[i][i]=0;
		if(i<=n)x[i][i]=0;
	}
/*	for(int i=1;i<=n;i++){
		for(int j=x[1];j<=x[0];j++)
			for(int q=x[1];q<=x[0];q++)
			tu[j][q]=0;tu[q][j]=0;
	}*/
	for(int i=1;i<=m;i++)
		if(xian[i][0]!=0){
			for(int j=1;j<=xian[i][0];j++)
				for(int k=1;k<=xian[i][0];k++){
					if(k==j)continue;
					nx[k][j][nx[k][j][0]++]=i;
			}
		}
		
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			int huafe=0x3f3f3f3f;int xx=-1,xxx=-1;
			for(int a=1;a<=xian[i][0];a++){
				for(int b=1;b<=xian[j][0];b++){
					int aa=xian[i][a];
					int bb=xian[i][b];
					if(huafe>x[aa][bb]){
						huafe=x[aa][bb];
						xx=aa;
						xxx=bb;}
				}
			}
			
			if(huafe==0){
				tu[i][j]=tin[i]+tin[j];
				tu[j][i]=tin[i]+tin[j];}
			else {
				int y=0x3f3f3f3f;
				if(nx[xxx][xx][0]>1){
					for(int i=1;i<=nx[xxx][xx][0]-1;i++)y=min(tin[nx[xxx][xx][i]],y);
				}
				tu[i][j]=tin[i]+huafe+y+tin[j];
				tu[j][i]=tin[i]+huafe+y+tin[j];
			}
		}
		}
for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
		for(int k=1;k<=m;k++){
			if(tu[i][j]>tu[i][k]+tu[j][k])tu[i][j]=tu[i][k]+tu[j][k];
		}	
		for(int i=1;i<=p;i++){
			cin>>a>>b;
			cout<<tu[a][b]<<"\n";
			
		}	
			
		
		
	
	
	return 0;
}
