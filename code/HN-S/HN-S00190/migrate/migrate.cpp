#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int c,t;
int n,d;
int x[N];
int ans=0;
void dfs(int y,int z){
	int sum=0;
	int temp=x[z]-x[y];
	if(2*d<=temp||temp<=d)return;
	for(int i=1;i<=d;i++){
		for(int j=1;j<=d;j++){
			if((i+j)==temp){
				sum++;
			}
		}
	}
	ans+=sum/2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<d){
			cout<<0;
		}else{
			for(int z=n;z>1;z--){
				for(int y=1;y<z;y++){
					dfs(y,z);
				}
			}
			cout<<ans<<endl;
			ans=0;
		}
	}
	return 0;
}
