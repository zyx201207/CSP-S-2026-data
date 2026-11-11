#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
string s;
char S[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	//s[0] = '0';
	while(n--){
		int a;
		string s1;
		cin >> a >> s1;
		for(int i = 0;i < a;i++)s += s1;
		l += a;	
	}
	for(int i = 0;i < l;i++){
		S[i + 1] = s[i];
	}
	for(int i = 1;i <= l;i++){
		if(S[i] != S[l + 1 - i])ans++,S[i] = S[l + 1 - i];
		//cout << S[i];
	}
	//cout << endl;
	//cout << s;
	cout << ans;
}
//6
//2 1000000000 a
//3 1000000000 a
//4 1000000000 a
//5 1000000000 b
//6 1000000000 b
//7 1000000000 b
