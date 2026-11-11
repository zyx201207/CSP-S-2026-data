#include<bits/stdc++.h>
using namespace std;
int c,t,n,s,mi;
long long d,a[2000010];
void dfs(int qs,int zj,int zd,long long ll){
	if(zj==zd){
		if(ll<mi){
			s=1;
			mi=ll;
		}else if(ll==mi){
			s++;
		}
		return;
	}
	for(int i=zj+1;i<=zd;i++){
		if(a[zj]+d>=a[i]){
			dfs(qs,i,zd,ll+1);
		}else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mi=n;
				s=0;
				dfs(i,i,j,1);
				if(s==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
}