#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	int a; 
	char c;
	long long length=0;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			s[length]=c;
			length++;
		}
	}
	for(int i=0;i<length/2;i++){
		if(s[i]!=s[length-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
//	for(int i=0;i<length;i++){
//		cout<<s[i];
//	}
	return 0;
}

