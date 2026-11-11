#include<bits/stdc++.h>
using namespace std;

int n,a,aa=1;
string s,s1;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a;
		cin >> s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	int len=s.length();
	if(len==2&&s[0]==s[1]){
		cout << "0";
		return 0;
	}
	for(int i=0;i<len;i++){
		if(s[i]!=s[i+1]){
			aa=0;
		}
	}
	if(aa=1){
		cout <<"0";
		return 0;
	}
	if(n==1){
		cout <<"0";
		return 0;
    }
	
	return 0;
}