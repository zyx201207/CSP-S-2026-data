#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],ans,m=INT_MAX,key;
void dfs(long long q,long long z,long long ci){
	if(ci>m)return;
	//cout<<q<<' '<<z<<endl;
	if(q==z){
		if(ci==m){
			key=2;
		}
		else if(ci<m){
			m=ci;
			key=1;
		}
		return;
	}
	for(int i=q+1;i<=z;i++){
		if(x[i]-x[q]<=d){
			dfs(i,z,ci+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>x[i];
    	ans=0;
    	for(int i=1;i<=n;i++){
    		for(int j=i+1;j<=n;j++){
			 key=0;
			 m=INT_MAX;
    			dfs(i,j,0);
    			if(key==2){
    				ans++;
				}
			}
		}
		cout<<ans<<endl;;
	}
	return 0;
}
  