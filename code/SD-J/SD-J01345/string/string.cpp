#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin)
freopen("string.out","w",stdout)
struct P{
	int b;
	char c;
}a[200005];
int n,ans;
string s;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].b;j++){
			s+=a[i].c;
		}
	} 
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
} 
