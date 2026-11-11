#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",s1="";
	long long n,cnt=0;
	cin >> n;
	for (long long i=1;i<=n;i++){
		int num=0;
		cin >> num;
		string zm="abcdefghijklmnopqrstuvwxyz";
		char c;
		cin >> c;
		for (int j=0;j<26;j++){
			if(c==zm[j]){
				for (int p=0;p<num;p++){
					s=s+zm[j];
			}	
				}
			
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout << 0;
	}
	else{
		for(int i=0;i<s.size()/2;i++){
		if(s1[i]!=s[i]){
			cnt++;
		}
	}
	}
	cout << cnt;
	
	return 0;
}
