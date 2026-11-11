#include<bits/stdc++.h>

using namespace std;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b;
	cin>>n;
	for(int i= 1;i<=n;i++){
		cin>>b>>a;
		for(int i = 1;i<=b;i++){
			s+=a;
		}
	}
	//cout<<s.size();
	int cnt = 0;
	for(int i = 0;i<s.size();i++){
		int l = s.size()-i-1;
		if(s[i] != s[i+l-i]){
			s[i] = s[i+l-i];
				cnt++;
		}
	}
	cout<<cnt;
	
	
	
	
	
	
	
	
	return 0;
}
