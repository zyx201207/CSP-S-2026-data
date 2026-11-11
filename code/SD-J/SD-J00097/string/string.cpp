#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,a[N],m,cnt;
string s,nw;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			nw[cnt]=s[i-1];
			cnt++;
		}
	}
	int ans=0;
	for(int i=0;i<cnt/2;i++){
		if(nw[i]!=nw[n+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}

