#include <bits/stdc++.h>
using namespace std;
int m=0;
string s;
long long len;
string ss[200007];
void ng(long long len){
	for (int i=0;i<=len/2;i++){
		if(s[i] != s[len-i-1]) m++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	while(n--){
		int m;
		char c;
		string s;
		cin >> m >> c;
		for (int i=1;i<=m;i++){
			s += c;
		}
		
	}
	len = s.size();
	ng(len);
	cout << m;
	return 0;
}
