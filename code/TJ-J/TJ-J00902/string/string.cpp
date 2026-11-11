#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int t1;
		char t2;
		cin>>t1>>t2;
		for(int j=0;j<t1;j++){
			s+=t2;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		int j=s.size()-1-i;
		if(s[i]!=s[j]){
			s[i]=s[j];
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}
