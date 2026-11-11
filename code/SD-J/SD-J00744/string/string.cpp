#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,ans=0,cnt=-1;
string a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>m>>s;
		cnt+=m;
		for(int j=1;j<=m;j++){
			a+=s;
		}
	}
	for(ll i=0;i<a.size()/2;i++){
		if(a[i]!=a[cnt-i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
