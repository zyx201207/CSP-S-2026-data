#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e5+10;
int a[N],s1;
string s;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}
	int ans=0;
	for(int i=0;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
//cout<<s<<" "<<mv<<"\n";
}
