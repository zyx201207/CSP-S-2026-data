#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[505],a[505][3],t[505][3],w[505];
bool b;
int dfs(int x,int y){
	if(x==y){
		return w[y];
	}else{
		long long sum=0x3F3F3F;
		for(int i=0;i<n;i++){
			if(k[i]==1){
				continue;
			}else if(a[i][0]==x){
				sum=min(sum,dfs(a[i][1],y)+t[i][1]+t[i][0]);
			}else if(a[i][1]==x){
				sum=min(sum,dfs(a[i][0],y)+t[i][1]+t[i][0]);
			}
		}
		return sum;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long cs=0,js=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	} 
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<2;j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>cs>>js;
		cout<<dfs(cs,js)+w[cs];
	}
	return 0;
}
