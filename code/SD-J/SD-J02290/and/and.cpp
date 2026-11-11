#include<bits/stdc++.h>
using namespace std;
int n,m,t,maxsum=-1;
bool f,ff;
long long a[200005];
bool cmp(const int a,const int b){return a>b;}
int dfs(int j,int cnt,int k){
	if(k==m) maxsum=max(maxsum,cnt);
	if(n-j+k<=m) return 0;
	else{
		dfs(j+1,cnt&a[j],k+1);
		dfs(j+1,cnt,k);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f=((a[i]-1&a[i])==0),ff=(a[i]==i-1);
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==2){
		sort(a+1,a+n+1,cmp);
		long long maxs=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) maxs=max(maxs,a[i]&a[j]);
		}
		cout<<maxs;
		return 0;
	} 
	if(f){
		sort(a+1,a+n+1,cmp);
		long long maxs=a[1];
		for(int i=2;i<=n;i++) maxs=maxs&a[i];
		cout<<maxs;
		return 0;
	}
	if(ff){
		sort(a+1,a+n+1,cmp);
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(i+1,a[i],1);
	cout<<maxsum;
	return 0;
}
