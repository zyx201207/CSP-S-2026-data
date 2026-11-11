#include<bits/stdc++.h> 
using namespace std;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++){
			s[len]=c;
			len++;
		}
			
	}
	
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
