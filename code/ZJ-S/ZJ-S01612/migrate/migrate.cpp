#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
int n,mn[N],mx[N],ans;
ll d,a[N];
map<int,int>mp[N];
void solve(int p){
	for(int i=p;i<=n;++i)mp[i].clear();
	memset(mn,0x3f,sizeof(mn));
	memset(mx,0,sizeof(mx));
	mn[p]=mx[p]=0;
	mp[p][0]=1;
	for(int i=p;i<=n;++i){
		if(mp[i][mn[i]]==2)++ans;
		for(int k=i+1;k<=n&&a[k]-a[i]<=d;++k){
			mn[k]=min(mn[k],mn[i]+1);
			mx[k]=max(mx[k],mx[i]+1);
			for(int j=mn[i];j<=mx[i];++j){
				if(mp[k][j+1]>2)continue;
				mp[k][j+1]+=mp[i][j];
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _;cin>>_>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1;i<n;++i)solve(i);
		cout<<ans<<'\n';
	}
	return 0;
}
