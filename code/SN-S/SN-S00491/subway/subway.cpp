//SN-S00491 韩亦宽 西安市第八十三中学 
#include<iostream>
#include<algorithm>
using namespace std;
int c,n,m,d,q,k,xi=1000000,a,e;
int w[500005],t[500005][505]={},x[100005],y[100005]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>e;
			t[a][i]=e;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		if(n==2){
			
			if(t[x[i]][1]!=0&&t[y[i]][1]!=0&&t[x[i]][2]!=0&&t[y[i]][2]!=0){
				cout<<min(t[x[i]][1]+t[y[i]][1],t[x[i]][2]+t[y[i]][2])<<endl;
			}
			else if(t[x[i]][1]!=0&&t[y[i]][1]!=0){
				cout<<w[x[i]]+w[y[i]]+t[x[i]][1]+t[y[i]][1]<<endl;
			}
			else if(t[x[i]][2]!=0&&t[y[i]][2]!=0){
				cout<<w[x[i]]+w[y[i]]+t[x[i]][2]+t[y[i]][2]<<endl;
			}
			else if(t[x[i]][1]!=0&&t[y[i]][2]!=0){
				for(int j=1;j<=m;j++){
					if(t[j][1]!=0&&t[j][2]!=0&&(t[j][1]+t[j][2])<xi){
						xi=t[j][1]+t[j][2];
					}
				}
				cout<<xi+w[x[i]]+w[y[i]]+t[x[i]][1]+t[y[i]][2]<<endl;
			}
			else{
				for(int j=1;j<=m;j++){
					if(t[j][1]!=0&&t[j][2]!=0&&(t[j][1]+t[j][2])<xi){
						xi=t[j][1]+t[j][2];
					}
				}	
				cout<<xi+w[x[i]]+w[y[i]]+t[x[i]][2]+t[y[i]][1]<<endl;
			}
		}
		if(n==1){
			cout<<w[x[i]]+w[y[i]]+t[x[i]][1]+t[x[i]][2]+t[y[i]][1]+t[y[i]][2]<<endl;
		}
	}
	return 0;
}
