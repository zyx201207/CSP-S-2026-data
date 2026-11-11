#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	long long a[200011];
	string c,s;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(ll j=0;j<a[i];j++){
			s[cnt]=c[i];
			cnt++;
		}
	}
	for(ll j=0;j<cnt/2;j++){
		for(ll k=cnt-1;k>cnt/2;k--){
			if(s[j]!=s[k]){
				ans++;
				break;
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
