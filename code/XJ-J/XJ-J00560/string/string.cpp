#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
string s="";
ll n;
ll len;
ll ans=1e9;
ll ai=0;
char a[maxn];
bool f(string s){
	for(ll l=0;l<=len/2;l++){
		if(s[l]!=s[len+1-l]){
			return false;
		}
	}
	return true;
}
void dfs(ll step,string ss,ll c){
	if(step==len){
		if(f(ss)){
			ans=min(ans,c);
		}
		return;
	}
	for(ll i=1;i<ai;i++){
		dfs(step+1,ss+=a[i],c+1);
	}
	dfs(step+1,ss+=s[step],c);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		char x;
		ll m;
		cin>>m>>x;
		for(ll i=0;i<m;i++){
			s+=x;
		}
		a[ai++]=x;
	}
	len=s.length();
	dfs(0,"",0);
	cout<<ans;
	return 0;
}