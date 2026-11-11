#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 2e5 + 10;
string s;
int sum = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		string s1(x,c);
		s += s1;
	}
	int mid;
	if(s.size() % 2 == 0){
		mid = s.size() / 2;
	}
	else{
		mid = s.size()/2+1;
	}
	for(int i = mid,j = mid;i >= 0,j <= s.size()-1;i--,j++){
		if(s[i] != s[j]) sum++;
	}
	cout << sum;
	return 0;
}