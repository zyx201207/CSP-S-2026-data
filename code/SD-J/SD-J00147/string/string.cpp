#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2*1e5+10; 
struct wd{
	ll num;
	char c;
} words[N];
ll n;
ll sum;
ll ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>words[i].num>>words[i].c;
		sum=sum+words[i].num;
	}ll l=1,r=n;
	ll ne_suq=words[1].num,ne_suh=words[n].num;
	for(int i=1;i<=sum/2;i++){
		ll j=sum+1-i;
		if(i>ne_suq){
			ne_suq=ne_suq+words[++l].num;
		}
		if(sum-j+1>ne_suh){
			ne_suh=ne_suh+words[--r].num;	
		}  
		if(words[l].c!=words[r].c){
			ans++;
			//cout<<words[l].c<<' '<<words[r].c<<'\n';
		}
	}cout<<ans<<'\n';
	return 0;
}

