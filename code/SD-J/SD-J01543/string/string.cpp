#include<bits/stdc++.h>
using namespace std;

long long n,a,ans=0;
string s,c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int j=0;j<a;j++){
			s=s+c;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			ans+=1;
		}
	}
	cout<<ans;
	return 0;
}
