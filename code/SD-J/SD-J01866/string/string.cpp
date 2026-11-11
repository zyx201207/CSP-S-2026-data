#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,n;
char c;
int ans;
int cnt;
string s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		ans+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int j=ans-1;
	for(int i=0;i<=ans/2-1;i++){
		if(s[i]!=s[j]){
			cnt++;
		}
		j--;
	}
	cout<<cnt;
	return 0;
}
