#include<bits/stdc++.h>
using namespace std;
int b[35][505],e[35][505],sj[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,cz;
	while(n){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>cz;
			cin>>b[cz][n];
		}
		n--;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]!=0&&b[i][j+1]!=0){
				e[i][j]=b[i][j]+b[i][j+1];
			}
		}
	}
	while(q){
		int x,y,ts;
		cin>>x>>y;
		if(x>y){
			ts=x;
			x=y;
			y=ts;
		}
	
		for(int i=1;i<=n;i++){
			if(b[x][i]!=0&&b[y][i]!=0){
				sj[i]=b[x][i]+b[y][i]+w[x]+w[y];
			}else if(b[x][i]!=0&&b[y][i]==0){
				int bf[y+5];
				for(int j=x;j<=y;j++){
					if(e[j][i]!=0&&b[y][i+1]!=0){
						bf[j]=e[j][i]+b[y][i+1]+b[x][i]+w[x]+w[y];
					}
				}
				sort(bf+x,bf+x+y);
				sj[i]=bf[x];
			}
		}
		sort(sj+1,sj+1+n);
		for(int i=1;i<=n;i++){
			if(sj[i]!=0){
				cout<<sj[i]<<endl;
				break;
			}
		}
		q--;
	} 
	return 0;
}
