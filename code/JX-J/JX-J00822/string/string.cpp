#include<bits/stdc++.h>
using namespace std;
int n,a,ans=0;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[0+i]!=s[s.size()-1-i]){
			s[0+i]=s[s.size()-1-i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}