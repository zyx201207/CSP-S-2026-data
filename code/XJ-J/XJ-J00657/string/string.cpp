#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e8;
ll n;
ll x[maxn];
char c[maxn];
string s1="",s2="";
void dfs1(ll step,char cc,ll xx){
	if(step==xx){
		return;
	} 
	//cout<<s1<<endl;
	s1+=cc;
	dfs1(step+1,cc,xx);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		dfs1(0,c[i],x[i]);
		
	}
	//cout<<s1<<endl;
	int len=s1.length();
	//cout<<len;
	for(int i=len-1;i>=0;i--){
		s2+=s1[i];
	}
	ll ans=0;
	for(int i=0;i<len/2;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
