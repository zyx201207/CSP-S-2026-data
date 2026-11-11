#include<bits/stdc++.h>
using namespace std;
int n;
struct a{
	
	int m;
	char c;	
	
}x[200010];

vector<char> s;
int cnt=0;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i].m >> x[i].c;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<x[i].m;j++){
			s.push_back(x[i].c);
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i] != s[s.size()-i-1]){
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
	
}
