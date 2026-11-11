#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,a,cnt,v,ans;
string s;
char x;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a>>x;
		v += a;
		for(int j = 1;j <= a;j++){
			s = s + x;
		}
	}ans = v - 1;
	for(int i = 0;i < v;i++){
		if(i >= ans){
			cout<<cnt;
			return 0;
		}
		if(s[i] != s[ans]){
			cnt++;
		}
		ans--;
	}cout<<cnt;
	return 0;
}
