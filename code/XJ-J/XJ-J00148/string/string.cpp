#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a;
	int size = 0;
	int cnt = 0;
	string s[10010];
	string x;
	cin >>n;
	for(int i = 0;i < n;i++){
		cin>>a;
		size += a;
		cin >> x;
		for(int j = 0;j<=a;j++){
			s[i+j] = x;
		}
	}
	
	
//	for(int i = 0;i < size;i++){
//		cout <<s[i];
//	}
	
	
	
	for(int i = 0;i < size;i++){
		if(s[i] != s[size-1-i]){
			break; 
		}
		else{
			cout<<0;
		}
	}
	for(int i = 0;i < size;i++){
		if(s[i] != s[size-1-i]){
			s[size-1-i] = s[i];
			cnt++;
		}
	}
	cout <<cnt;
	return 0;
} 
