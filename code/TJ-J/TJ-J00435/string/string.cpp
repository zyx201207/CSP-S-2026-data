#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool check(string s){
	string s1 = s;
	reverse(s.begin(),s.end());
	return s1 == s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int k;
		string c;
		cin>>k>>c;
		for(int i = 1;i <= k;i++)s += c;
	} 
	long long ans;
	if(check(s))return cout<<0,0;
	if(s.size() % 2 == 1){
		for(int i = s.size() / 2 - 1,j = s.size() / 2 + 1;i > 0 and j < s.size();i--,j++){
			if(s[i] != s[j]){
				ans++;
			}
		} 
		if(s[0] != s[s.size() - 1])ans++; 
	}
	else {
		for(int i = s.size() / 2,j = s.size() / 2 - 1;i > 0 and j < s.size();i++,j--){
			if(s[i] != s[j]){
				ans++;
			}
		} 
	}
	cout<<ans;
	return 0;
} 
