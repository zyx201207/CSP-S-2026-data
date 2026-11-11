#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int sum;
		char a;
		cin>>sum;
		cin>>a;
		while(sum--){
			s+=a;
		}
	}
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				ans++;
			}
		}
	cout<<ans;
	return 0;
}
