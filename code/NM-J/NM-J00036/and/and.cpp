#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
long long a[N];
long long Max=-1;
long long INF=1073741823;
void dfs(int k,long long ans,int ii){
	if(k==m){
		Max=max(ans,Max);
		return;
	}
	if(ans<=Max || ii==n)
	return;
	for(int i=ii+1;i<=n;i++){
		dfs(k+1,ans&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)
		Max=max(a[i],Max);
		cout<<Max;
		return 0;
	}
	else
		dfs(0,INF,1);
		cout<<Max;
	return 0;
}
