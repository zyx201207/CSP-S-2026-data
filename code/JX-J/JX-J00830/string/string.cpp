#include<bits/stdc++.h>
using namespace std;
int n,a,l,ans;
string c,s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		l+=a;
	}
	s1=s.substr(0,(l/2));
	s2=s.substr((l/2)+1);
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[s2.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}