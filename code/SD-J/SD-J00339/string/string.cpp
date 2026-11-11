#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	s1=s;
	reverse(s.begin(),s.end());
	long long ch1=0,ch2=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s1[i]){
			ch1++;
		}
	}
	for(int i=s.size()/2;i<s.size();i++){
		if(s[i]!=s1[i]){
			ch2++;
		}
	}
	long long ans=min(ch1,ch2);
	cout<<ans;
	return 0;
}
