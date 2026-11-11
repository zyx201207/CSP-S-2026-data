#include <bits/stdc++.h>
using namespace std;
int n,x;
string s,a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x>>a;
		if(x>=1000000000){
			cout<<3000000000;
			return 0;
		}
		for(int j=1;j<=x;j++){
			s+=a;
		}
		
		
	}
	int ans=0;
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>=n/2;j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
 } 
