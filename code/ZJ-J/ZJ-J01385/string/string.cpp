#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	while(n--){
		int a;
		cin>>a;
		char x;
		cin>>x;
		for(int i=1;i<=a;i++){
			s+=x;
		}
	}
	int ans=0;
	int l=s.size();
	for(int i=0;i<=(l-1)/2;i++){
		int j=l-i-1;
		if(s[i]!=s[j]){
			ans++;
		}
		else continue;
	}
	cout<<ans;
	return 0;
}
