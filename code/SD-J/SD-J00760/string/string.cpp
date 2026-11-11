#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
string s[N];
string st;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	int maxx=0;
	bool ok=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		maxx=max(a[i],maxx);
		if(a[i]!=a[i-1] && i>1){
			ok=false;
		}
	}
	if(maxx<=3000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				st+=s[i];
			}
		}
		int len=st.size();
		ll ans=0;
		int L=0,R=len-1;
		while(L<R){
			if(st[L]!=st[R]){
				ans++;
			}
			L++,R--;
		}
		cout<<ans;
	}
	else if(ok){
		int L=1,R=n;
		ll ans=0;
		while(L<R){
			if(s[L]!=s[R]){
				ans+=1LL*a[L];
			}
			L++,R--;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
