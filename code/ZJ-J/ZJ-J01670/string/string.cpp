#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,x;
string ss;
int ans;
int hws(string t){
	for (int i = 1;i*2 <= t.size();i++){
		if (t[i] != t[t.size()-i])ans++; 
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	s += "?";
	for (int i = 1;i <= n;i++){
		cin >> x >> ss;
		for (int j = 1;j <= x;j++)s += ss; 
	}
	//cout << s;
	cout << hws(s);
	//if(hws(s)){
	//	cout << 1;
	//}
	//else cout << 0;
	//cout << s;
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
