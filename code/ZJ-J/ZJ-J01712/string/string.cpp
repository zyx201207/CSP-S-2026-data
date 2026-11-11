#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,a,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(a>=1000000){
			cout<<300000000;
			return 0;
		}
		while(a--) s+=c;
	}
	int l=s.size();
	if(l%2==1){
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]) ans++;
		}
	}
	else{
		for(long long i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]) ans++;
		}
	}
	cout<<ans;
}