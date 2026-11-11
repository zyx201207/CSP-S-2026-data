#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s=s+x;
		}
	}
	int l=s.size();
	for(int i=0;i<=l/2-1;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}