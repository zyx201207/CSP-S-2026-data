#include<bits/stdc++.h>
using namespace std;
long long x[2000005],cf[2000005];unsigned long long d;
int n,c,t,N,lu[2000005],inf=0x3f3f;

int dfs(int z,int ul){
	
	if(z>n){
	return 0;	
	}
	for(long long i=z;i<=n;i++){
	long long mf=cf[i],mfs=z;
	while(mf<=d){
		mf+=cf[++mfs];
		dfs(z+mfs-1,mf);
	}	
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	memset(lu,inf,sizeof(lu));
	int y;
	for(int ii=1;ii<=t;ii++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[ii];
		}
		for(int i=1; i<n; i++) {
		if(x[i+1]>0&&x[i]<0){
			cf[i]=abs(x[i+1]-x[i]);
		}else{
		cf[i]=abs(abs(x[i+1])-abs(x[i]));	
		}}
		dfs(1,0);
		
	
	}
	
	cout<<y;

	return 0;
}
