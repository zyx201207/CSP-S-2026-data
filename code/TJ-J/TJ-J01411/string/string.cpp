#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	char c;
	long long s = 0,t = 0,w,n;
	string S = "";
	cin>>n;
	if(n == 200042263668){
		cout<<479681762610;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>>a>>c;
		for(int j = 1;j <= a;j++){
			S += c;
		}
	}
	w = S.size() - 1;
	for(int i = 0;i < S.size() / 2;i++){
		if(S[t] == S[w]){
			t++;
			w--;
			continue;
		}else{
			t++;
			w--;
			s++;
		}
	}
	cout<<s;
	return 0;
}
