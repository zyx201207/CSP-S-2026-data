#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
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