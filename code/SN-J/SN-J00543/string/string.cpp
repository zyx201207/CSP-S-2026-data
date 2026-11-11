#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;string s="";cin>>n;
	for(int i=1;i<=n;i++){
		long long a;char c;cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	string cmp=s;reverse(cmp.begin(),cmp.end());
	long long ans=0,len=s.size();
	if(cmp==s){
		cout<<0;return 0;
	}else{
		for(int i=0;i<len/2;i++){
			if(s[i]==s[len+1-i]){
				continue;
			}else{
				s[len+1-i]=s[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
