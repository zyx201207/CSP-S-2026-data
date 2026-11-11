#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,b;
	string s,a;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b >>a;
		for(int j=1;j<=b;j++){
			s=s+a;	
		}
	}for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
