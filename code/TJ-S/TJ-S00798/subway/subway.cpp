#include<bits/stdc++.h>
using namespace std;
struct sub{
	int sta;
	int t;
}a[500005][500005];
string b[500005];
int dt[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>dt[i];
	}
	for(int i=1;i<=n;i++){
		int zhan;
		cin>>zhan;
		for(int j=1;j<=zhan;j++){
			cin>>a[i][j].sta>>a[i][j].t;
			b[a[i][j].sta]+=(i+'0')+'.';
		}	
	}
	int sum=0;
	for(int i=1;i<=q;i++){
		int qd,zd,qdx=0,zdx=0;
		cin>>qd>>zd;
		sum+=dt[qd]+dt[zd];
		for(int j=1;j<=n;j++){
			int k=1;
			while(a[j][k].sta!=0){
				if(a[j][k].sta==qd){
					qdx=i;
				}
				if(a[j][k].sta==zd){
					zdx=i;
				}
				if(qdx!=0&&zdx!=0){
					
				}
			}
		}
	}
return 0;
} 
