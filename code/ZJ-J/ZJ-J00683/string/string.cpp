#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n;s="#";
	for(int i=1;i<=n;i++){
		char k;
		ll op;cin>>op>>k;
		while(op--)s+=k;
	}
	for(int i=1;i<s.length();i++){
		ll j=s.size()-i;
		if(s[i]!=s[j]){
			s[j]=s[i];
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
