#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,d;
int x[N];
int l_cnt[N],r_cnt[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			vector<int>r;
			for(int p=i;p<j;p=upper_bound(x+1,x+1+n,x[p]+d)-x-1){
				if(p!=i)r.push_back(p);
			}
			vector<int>l;
			for(int p=j;p>i;p=lower_bound(x+1,x+1+n,x[p]-d)-x){
				if(p!=j)l.push_back(p);
			}
			int cnt=0;
			for(int k=0;k<r.size();k++){
				if(r[k]!=l[l.size()-k-1])cnt++;
			}
			if(cnt==1)ans++;
		}
	}
	cout<<ans<<endl;
}
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}