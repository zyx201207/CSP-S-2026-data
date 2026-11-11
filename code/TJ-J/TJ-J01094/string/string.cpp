#include<bits/stdc++.h>
using namespace std;
long long n;
long long l;
char c;
string s,t;
void solve(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>l>>c;
		for(long long j=1;j<=l;j++){
			s+=c;
		}
	}
	t=s;
	reverse(s.begin(),s.end());
	long long ans=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans;
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
