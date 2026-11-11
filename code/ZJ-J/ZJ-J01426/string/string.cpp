#include <bits/stdc++.h>
using namespace std;
int n;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i = 1;i<=n;i++){
		int a;
		char c;
		cin >>a;
		cin >>c;
		for(int i = 1;i<=a;i++){
			S+=c;
		}
	}
	long long ans =0;
	for(int i = 0,j=S.length()-1;i<S.length()/2;i++,j--){
		if(S[i]==S[j]){
			continue;
		}
		ans++;
	}
	cout <<ans;
	return 0;
}
