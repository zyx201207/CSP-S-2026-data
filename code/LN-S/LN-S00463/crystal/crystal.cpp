#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>1;i--){
		memset(s,0,sizeof(s));
		bool first=1;
		int cnt=0;
		for(int j=i-1;j>=1;j--){
			s[i]=0;
			s[j]=a[i]-a[j]+s[j+1];
			if(m>=s[j] && first){
				cnt+=2;
				first=0;
			}
			else if(m>=s[j])cnt+=1;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}

