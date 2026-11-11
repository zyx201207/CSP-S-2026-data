#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],ans;
string ss;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=2;i<=n;i++){
		if(s[i]!=s[i-1]){
			ok=0;
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ss=ss+s[i];
		}
	}
	for(int i=0;i<=ss.size()/2;i++){
		if(ss[i]!=ss[ss.size()-i]) ans++;
	}
	cout<<ans;
	return 0;
}
