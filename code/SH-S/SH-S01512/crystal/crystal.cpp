#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int n,m,a[N],ans,cnt[N],s[N];
bool cmp(int p,int q){
	return p>q;
}
void solve(int l){
	memset(s,0xfffffff,sizeof(s));
	for(int i=1;i<=n;i++){
		if(a[l]-a[i]<0){
			s[i]=0xffffff;
			continue;
		}
		s[i]=a[l]-a[i];
	}
	int mn=m;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]==0xfffffff) continue;
		mn-=s[i]; 
		if(mn<0) return;
		cnt[l]++;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,cnt[i]);
	}
	cout<<ans<<endl;
	return 0;
} 
