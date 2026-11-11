#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
int n,m;
ll ans;
string turn(ll x){
	string s;
	int cnt=0;
	while(x>0){
		char c=(x&1LL)+'0';
		s+=c;
		x=x>>1LL;
		cnt++;
	}
	while(cnt<=30){
		s+='0';
		cnt++;
	}
	reverse(s.begin(),s.end());
	return s;
}
void solve(){
	cin>>n>>m;
//	cout<<m<<endl;
	vector<string> a(n+1);
	vector<int> vis(n+1);
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		a[i]=turn(t);
//		cout<<a[i]<<endl;
	}
	int k=1;
	int maxn=0;
	for(int i=0;i<=30;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			string s=a[j];
			if(s[i]=='1'&&vis[j]>=maxn){
				cnt++;
				vis[j]++;
			}
		}
//		cout<<maxn<<' '<<i<<' '<<cnt<<endl;
		if(cnt>=m){
			maxn++;
			ans+=1LL<<(30-i);
			k=0;
		}
	}
	cout<<ans;
}
int main(){
	fast;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
