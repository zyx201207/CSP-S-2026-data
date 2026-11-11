#include<bits/stdc++.h>
using namespace std;
long long n,s,ans=0;
string a,b="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>a;
		for(int j=1;j<=s;j++){
			b+=a;
		}
	}
	for(int i=0;i<(b.size()/2);i++){
		if(b[i]!=b[b.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}