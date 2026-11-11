#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005]={},a[500005][500005]={},t[500005][500005]={},x[500005]={},y[500005]={},k[500005]={};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		long long sum=0,line;
		bool e=0,b=0;
		sum+=w[x[i]]+w[y[i]];
		for(int z=1;z<=n;z++){
			for(int j=1;j<=m;j++){
				if(a[z][j]==x[i]){
					e=1;
					break;
				}
				if(a[z][j]==y[i]){
					b=1;
					break;
				}
			}
			if(e&&b){
				line =z;
				break;
			}
		}
		for(int j=x[i];j<=x[i];j++){
			sum+=t[line][j];
		}
		cout<<sum<<'\n';
	}
	fclose(stdin);
	return 0;
}
