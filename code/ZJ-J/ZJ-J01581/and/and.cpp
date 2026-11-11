#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mcx=2e5+5;
int n,m,cnt[35],ans,a[mcx];
bool cmp(int A,int B){return A>B;}
int calc(){
	int ret=0;
	for(int i=0;i<30;i++){
		if(cnt[i]==m)ret=ret+(1<<i);
	}
	return ret;
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1]<<'\n';
		return 0;
	}
		for(int i=1;i<=m;i++){
			for(int j=0;j<30;j++){
				if(a[i]&(1<<j))cnt[j]++;
			}
		}
		ans=max(ans,calc());
		for(int i=1;i+m<=n;i++){
			int nxt=i+m;
			for(int j=0;j<30;j++){
				if(a[nxt]&(1<<j))cnt[j]++;
			}
			for(int j=0;j<30;j++){
				if(a[i]&(1<<j))cnt[j]--;
			}
			ans=max(ans,calc());
		}
		cout<<ans<<'\n';
	return 0;
}
