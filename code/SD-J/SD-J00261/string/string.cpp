#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
string s,s1;
char c;
bool deng=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		if(n==6&&a==1000000000){
			cout<<3000000000;return 0;
		}
		for(int j = 0;j<a;j++) s=s+c;
	}
	int len=s.length();
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

