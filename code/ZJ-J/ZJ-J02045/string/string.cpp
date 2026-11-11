#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int cc;
int ans;
int a[N];
char c[N];
char s[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s[++cc]=c[i];
		}
	}
	for(int i=1;i<=cc/2;i++){
		if(s[i]!=s[cc-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
