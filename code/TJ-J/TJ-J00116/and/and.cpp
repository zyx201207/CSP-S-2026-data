#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200002],d[200002],ans;
void dfs(long long m,long long n){
	if(m==b){
		ans=max(ans,n);
		return;
	}
	for(int i=0;i<a;i++){
		if(d[i]==0){
			d[i]=1;
			dfs(m+1,n&c[i]);
			d[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	for(long long i=0;i<a-b+1;i++){
		d[i]=1;
		dfs(1,c[i]);
		d[i]=0;
	}
	cout<<ans;
	return 0;
}
