#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+5;
int n;
string s;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		string c;
		cin>>c;
		for(int i=1;i<=t;i++){
			s+=c;
		}
	}
	i64 len=s.size();
	i64 ans=0;
	for(int i=0,j=len-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
