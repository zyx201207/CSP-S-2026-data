#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,cnt=0;
	string s;
	cin>>n;
	for (int i= 1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for (int i = 0;i < a;i++) s.push_back(c);
	}
	int k = s.size();
	if (k%2==0){
		k =k/2-1;
		int m=k-1;
		for (int i = k+1;i < s.size();i++){
			if (s[i]!=s[m]) cnt++;;
			m--;
		} 
	}
	else{
		k = k/2;
		int m=k-1;
		for (int i = k+1;i < s.size();i++){
			if (s[i]!=s[m]) cnt++;
			m--;
		} 
	}
	cout<<cnt;
	return 0;
}
