# include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[1000000],b[510][500100],t[510][500100],c[550];
//								能到达第几个站台 路线   站台时间 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++){
			cin>>b[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>head>>tail;
		for(int j=1;j<=n;j++){
			for(int w=1;w<=c[i];w++){
				if(b[j][w]==head){
					
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
