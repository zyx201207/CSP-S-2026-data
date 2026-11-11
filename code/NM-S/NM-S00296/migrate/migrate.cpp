#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000000],sum,cnt,dl;
void dfs(int l,int r){
	if(l==r){
		sum++;
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			dl++;
			dfs(i,r);
			dl--;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;
				dfs(i,j);
				if(sum==2) cnt++;
			}
		}
		//cout<<cnt<<endl;
		if(d>=2*(x[2]-x[1])) cout<<n-4+1<<endl;
		else if(d>=3*(x[2]-x[1])) cout<<n-5+1<<endl;
		else if(d>=4*(x[2]-x[1])) cout<<n-6+1<<endl;
		else if(d>=5*(x[2]-x[1])) cout<<n-7+1<<endl;
	return 0;
}
