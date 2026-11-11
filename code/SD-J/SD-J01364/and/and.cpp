#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N];
bool vis[N];
int n,m;
bool cmp(long long x,long long y){
	return x>y;
}
long long dfs(int x,long long ans,int y){
	if(y==m)return ans;
	vis[x]=1;
	long long maxn=-100;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			maxn=max(maxn,dfs(i,(ans&a[i]),y+1));
		}
	}
	vis[x]=0;
	return maxn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	bool f=0,o=0;
	long long ma=-100;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if((a[i]&(a[i]+1))>0)f=1;
		if(a[i]>=4)o=1;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(!f){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	if(!o){
		int cnt3,cnt2,cnt1;
		cnt3=cnt2=cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3)cnt3++;
			if(a[i]==2)cnt2++;
			if(a[i]==1)cnt1++;
		}
		if(cnt3>=m)cout<<3;
		else if(cnt3+cnt2>=m)cout<<2;
		else if(cnt3+cnt1>=m)cout<<1;
		else cout<<0;
		return 0; 
	}
	ma=-100;
	for(int i=1;i<=n;i++){
		ma=max(ma,dfs(i,a[i],1));
	}
	cout<<ma;
	return 0;
}


