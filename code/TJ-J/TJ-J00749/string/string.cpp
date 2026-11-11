#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//·¢ÈÈopen
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int a[20005];
	char c[20005];
	for(int i = 1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	char s[1000005];
	int l = 0;
	int r = 0;
	for(int i = 1;i<=n;++i){
		l = r;r+=a[i];
		for(int j = l;j<=r;++j){
			s[j] = c[i];
		}
	}
	int ans = 0;
	for(int i = 1;i<=r/2;++i){
		if(s[i]!=s[r-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
