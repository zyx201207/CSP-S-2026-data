#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a[n][d],t[n][m],tu[(n+1)*n/2][(n+1)*n/2],w[(n+1)*n/2],k[n];
	for(int i=0;i<(n+1)*n/2;i++){
		for(int j=0;j<(n+1)*n/2;j++){
		    tu[i][j]=-1;
	    }
	}
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
		for(int j=0;j<k[i];j++){
			for(int z=j;z<k[i];z++){
				tu[a[i][j]][a[j][z]]=t[i][a[i][z]];
			}
		}
	}
	for(int i=0;i<q;i++){
		int x=0,y=0,yll=0;
		long long sum=w[x]+w[y];
		cin>>x>>y;
		while(yll!=y){
			while(tu[x][yll]==-1||x==yll){
				yll++;
			}
			x=yll;
			sum+=tu[x][yll];
		}
		cout<<sum;
	}
	return 0;
}
