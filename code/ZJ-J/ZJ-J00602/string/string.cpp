#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[200005];
char c[200005];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<s.size();i++){
		s1+=s[s.size()-1-i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
