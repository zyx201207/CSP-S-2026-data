#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,m;
int a[N];
int maxn=INT_MIN;
int maxi,max2i;
int sum;
bool f;
void dfs(int nm,int sumn,int stp){
	if(nm==m){
		maxn=max(maxn,sumn);
		return;
	}
	if(stp+m-nm-1>n)return;
	if(stp>n)return;
	if(nm==0)dfs(nm+1,a[stp],stp+1);
	else dfs(nm+1,sumn&a[stp],stp+1);
	dfs(nm,sumn,stp+1);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxi){
			max2i=maxi;
			maxi=a[i];
		}else if(a[i]>=max2i){
			max2i=a[i];
		}
		if(!f){
			sum=a[i];
			f=true;
		}else sum=sum&a[i];
	}if(m==1){
		cout<<0<<'\n';
		return 0;
	}if(m==n){
		cout<<sum<<'\n';
		return 0;
	}dfs(0,0,1);
	cout<<maxn<<'\n';
	return 0;
}

