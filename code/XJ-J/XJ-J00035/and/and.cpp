#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+5;
int a[N];
bool used[N];
int n,m,maxn,ans,maxnx,minnx=INT_MAX,idx;
int dfs1(int step,int current,int idx){
	if(step>=m) return maxn;
	used[idx]=true;
	maxn=INT_MIN;
	for(int i=1;i<=n&&used[i]==false;i++){
		used[i]=true;
		maxn=max(current&a[i],maxn);
		if(step<m){
			dfs1(step+1,current&a[i],i);
		}
		used[i]=false;
	}
	used[idx]=false;
	return maxn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxnx=max(a[i],maxnx);
		if(a[i]<minnx){
			minnx=min(a[i],minnx);
			idx=i;
		}
	}
	sort(a+1,a+n+1,[](const int &a, const int &b){
		return a>b;
	});
	if(n<=20){
		for(int i=1;i<=n;i++){
			fill(used,used+n+1,false);
			maxn=0;
			ans=max(ans,dfs1(1,a[i],i));
		}
	}
	else if(m==1){
		cout<<maxnx<<'\n';
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n&&i!=idx;i++){
			ans&=a[i];
		}
	}else{
		ans=0;
	}
	cout<<ans;
	return 0;
	
}
