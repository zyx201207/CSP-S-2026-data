#include <bits/stdc++.h>
using namespace std;

bool huiwen(string S, int len){     //布尔函数：判断是否为回文 
	string S1;
	for (int i = len-1;i >= 0;i--){
		S1 += S[i];
	} 
	bool state = 1;
	for (int i = 0;i < len;i ++){
		if (S[i] != S1[i]){
			state = 0;
			break;
		}
	}if (state == 0){
		return false;
	}else{
		return true;
	}
} 


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len = 0;
	cin >> n;
	string S;
	for (int i = 0;i < n;i ++){
		int a;
		cin >> a;
		char s;
		cin >> s;
		for (int j = 0;j < a;j ++){
			S += s;
		}
		len += a;
	} 
	if (huiwen(S,len) == 1) cout << 0;
	else{
		string S1;
		for (int i = len-1;i >= 0;i--){
			S1 += S[i];
		} 
		int dif = 0; 
		for (int i = 0;i < len;i ++){
			if (S[i] != S1[i]){
				dif += 1;
			}
		}
		cout << dif / 2;
	}
}

