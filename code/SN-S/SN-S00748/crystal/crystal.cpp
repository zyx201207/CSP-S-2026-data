#include<bits/stdc++.h>
using namespace std;
long long ans[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>ans[i];
	}
	sort(ans+1,ans+n+1);
	long long i,totm=0;
	for(i=1;totm<=m;i++){
		totm+=(ans[i+1]-ans[i])*i;
	}
	cout<<i-1;
	return 0;
} 
