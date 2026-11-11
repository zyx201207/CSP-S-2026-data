#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long ai;
		char ci;
		cin>>ai>>ci;
		for(int j=1;j<=ai;j++){
			s+=ci;
		}
	}
	long long cnt=s.size()-1,ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[cnt-i]){
			ans++;
		}
	}
	cout<<ans;
}
