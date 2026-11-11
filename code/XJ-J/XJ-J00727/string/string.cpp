#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,c=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		c+=k;
		char d;
		cin>>d;
		for(int j=1;j<=k;j++){
			s+=d;
		}
	}
	for(int i=0;i<c/2;i++){
		if(s[i]!=s[c-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}