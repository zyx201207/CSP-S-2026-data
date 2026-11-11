#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
bool flag=true,po=false;
ll n,m,a[500005],s[500005],cnt,ans=-1;
ll dfs(ll b,ll c){//从下标多少开始统计/要统计几个？ 
	ll tmp=a[b];
	for (ll k=b;k>=b-c;k--){
		tmp=max(tmp,a[b]-a[k]);
		//cout<<"tmp="<<tmp<<'\n';
	}
	return tmp;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//crystal
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
		if (i!=1&&a[i-1]==a[i]) po=true;
		s[i]=s[i-1]+a[i];
//		if (i=1&&)
		if (a[i]!=i) flag=false;
	} 
	if (flag){
		for (ll j=1;j<=n;j++){
			if (s[j]>m){ 
				cout<<j<<'\n';
				break;
			}/*10 20
1 2 3 4 5 6 7 8 9 10*/
		}
		return 0;
	}
	sort(a+1,a+1+n);
	ll scp=0,dans=0;
	for (ll j=n;j>=2;j--){
		for (ll i=2;i<=n;i++){
			scp=dfs(j,i);
			if (scp>ans){
				ans=scp;
				dans=i+1;
			}//疑似应该也许似乎好像O(n^3) 
			//cout<<ans<<'\n';
		} 
	}
	//cout<<"ans"<<ans<<'\n';
	if (po) cout<<dans-1<<'\n';
	else cout<<dans<<'\n';
//	int w=(n%2==1)?((n >> 1)+1):(n >> 1);
//	//cout<<w<<endl;
//	while (a[w]==a[w+1]) w++;
//	//cout<<w<<endl;
//	for (ll i=1;i<w;i++){
//		ans+=(a[w]-a[i]);
//		cnt++;
//		//if (ans>=m) break;
//	}
//	cout<<cnt+1<<'\n';
	
	// Never gonna give you up!!!
	//LG:1101517 
	//DP! 
	return 0;
}
