#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,x,k,cnt;
string s[N],y;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x>=1e6){
			cout<<'0';
			return 0;
		}
		for(int j=1;j<=x;j++){
			k++;
			s[k]=y;
		}
	}
	for(int i=1;i<=k/2;i++){
		if(s[i]!=s[k-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
