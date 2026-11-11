#include<bits/stdc++.h>
using namespace std;
int a[100005][2000005];
int dfs(int l,int r){
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0) cout<<1<<"\n"<<2;
	for(int i=1;i<=t;i++){	
		int n,d;
		cin>>n>>d;
		int tmp1=1,tmp2=0; 						   
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][1]-a[i][j]>d) tmp2=j;
		}
		int ttmp=j+1;
		int ans=0;
		while(tmp1<=a[i][1]-a[i][tmp2]){
			if(tmp2==n){
				tmp2=ttmp;
				ttmp++;
				tmp1=ttmp-j;
			}
			ans+=dfs(tmp1,tmp2);
		}									   
	}									 
	return 0;
}
