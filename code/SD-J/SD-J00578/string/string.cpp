#include<bits/stdc++.h>
using namespace std;
bool ishw(string s){
	int len=s.size();
	for(int i=0;i<len-i+1;i++){
		int tmp=len-i-1;
		if(s[i]!=s[tmp])
			return 0;
	}
	return 1;
}
int hw(string s){
	int ans=0;
	for(int i=0;i<s.size()-1-i;i++){
		int tmp=s.size()-1-i;
		if(s[i]!=s[tmp]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int tmp;
		char ch;
		cin>>tmp>>ch;
		if(tmp==1){
			s=s+ch;
			continue;
		}
		for(int j=1;j<=tmp;j++){
			s=s+ch; 
		}
	}
	if(ishw(s)==1){
		cout<<0<<endl;
		return 0;
	}
	cout<<hw(s)<<endl;
	return 0;
}//Trick||Treat!
