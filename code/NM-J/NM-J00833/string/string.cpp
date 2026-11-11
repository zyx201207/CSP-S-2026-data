#include<bits/stdc++.h>
using namespace std;
int l;
char c;
string s;
int main(){
	freopen("string.exe","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	while(n--){
		cin>>l>>c;
		while(l--){
			s+=c;
		}
	}
	long long len=s.size();
	long long ans=0;
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
} 
