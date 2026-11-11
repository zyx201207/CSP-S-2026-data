#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,x[2000001],ans;
int tj(int u,int v){
	if(x[v]-x[u]<=d) return 1;
	int i=u,j=n,ans=0;
	while(i<j-1){
		if(u+d>x[i]) i=(i+j)/2;
		else if(u+d<x[i]) j=(i+j)/2;
		else break;
	}
	for(int k=u+1;k<=i;k++){
		ans+=tj(k,v);
		if(ans>2) break;
	}
	return ans;
}
bool twi(int i,int j){
	return tj(i,j)==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d,ans=0;
		int c1,c2,flag=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1 && flag){
				if(i==2) c1=x[i]-x[i-1];
				else{
					c2=c1,c1=x[i]-x[i-1];
					if(c1!=c2) flag=0;
				}
			}
		}
		if(flag){
			cout<<n-3<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans+=twi(i,j);
		cout<<ans<<endl;
	}
	return 0;
}
