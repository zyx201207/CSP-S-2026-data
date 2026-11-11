#include<bits/stdc++.h>
using namespace std;

long long ma=-1;
int n,m;
vector<long long> v(200005,0);
void dfs(int x,int step,long long sum){
	
	if(step>=m){

		
		ma=max(ma,sum);
		return;
	}
	int ss=n-(m-step)+1;
	
	for(int j=x+1;j<=ss;j++){
		
		long long s=sum&v[j];
		dfs(j,step+1,s);
	}
}
int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,v[i]);
		
	}
	cout<<ma;
	return 0;
}
