#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout5
	int n;
	cin>>n;
	string s="";
	while(n--){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	reverse(s.begin(),s.end());
	int len=s.size(),ans=0;
	if(len%2==1){
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1]){
				ans++;
			}
		}
	}else{
		for(int i=0;i<len/2-1;i++){
			if(s[i]!=s[len-i-1]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
