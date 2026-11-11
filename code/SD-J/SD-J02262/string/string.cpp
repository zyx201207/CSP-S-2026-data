#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s=""; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2+1;i++){ 
		if(s[i]!=s[s.size()-i-1]){
			ans++;
			s[s.size()-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0;
}//³¬Ê±
//48
