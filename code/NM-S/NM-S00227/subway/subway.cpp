#include<bits/stdc++.h>
using namespace std;
const int MAX=1e9+5;
int c,n,m,d,q,p,d1,v1;
long long k[MAX][MAX],w[MAX];
int start[1000],end[1000];
int sum[1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[MAX];
	}
	for(int i=1;i<m;i++){
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>d1>>v1;
			k[i][d1]=v1;
		}
	}
	for(int i=0;i<q;i++){
		cin>>start[i]>>end[i];
	}
	int j,u;
	for(int i=0;i<q;i++){
		int qs=start[i];
		int qj=start[i];
		for(j=1;j<=m;j++){
			if(k[j][1]==qs){
				sum[i]+=w[qs];
				sum[i]+=k[j][qs];
			}
		}
		for(u=1;u<=m;u++){
			if(k[u][1]==qj){
				sum[i]+=w[qj];
				sum[i]+=k[u][qj];
			}
			if(j==u){
				for(int f=qs;f<qj;f++){
					sum[i]+=k[f];
				}
			}
			else{
				sum[i]+=k[u][qj+1];
				sum[i]+=k[j][qj+1];
			}
		}
	}
	for(int i=0;i<q;i++){
		cout<<sum;
	}
    return 0;
}
