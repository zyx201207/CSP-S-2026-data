#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,best=1e9,start,end;
long long zt[10001]={0},lx[100001][100001]={0},lt[100001][100001]={0};
void cf(long long now,long long time){
	if(now==end){
		best+=zt[end];
		return;
	}
	if(now==start){
		best+=zt[start];
	}
	for(int i=1;i<=n;i++){
		if(lx[i][now]==1){
			best+=lt[i][now];
			now++;
			cf(now,time);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zt[i];
	}
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		for(int j=1;j<=c;j++){
			int z;
			int t;
			cin>>z>>t;
			lt[i][z]=t;
			lx[i][j]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start>>end;
		cf(start,0);
		cout<<best<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

