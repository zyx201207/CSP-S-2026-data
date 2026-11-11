#include<bits/stdc++.h>
using namespace std;
char c[1000000];
long long l=1,ans,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char x;
		cin>>t>>x;
		while(t--){
			c[l++]=x;
		}
	}
	for(int i=1;i<=l/2;i++){
		if(c[i]!=c[l-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
