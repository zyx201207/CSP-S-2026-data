#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],pre[N],ans=1;
unordered_map<int,int>cnt;
unordered_map<int,bool>mk;
int find_pos(int x,int y,int v){
	int l=x,r=y;
	while(l<=r){
		int mid=l+r>>1;
		if(v*(r-l+1)-(pre[r]-pre[l-1])<=m){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;++i){
		if(mk[a[i]]){
			continue;
		}
		int p=find_pos(1,i-1,a[i]);
		if(a[i]*(i-p)-(pre[i-1]-pre[p-1])<=m){
			ans=max(ans,i-p+cnt[a[i]]);
			mk[a[i]]=1;
		}
	}
	cout<<ans;
	return 0;
}
