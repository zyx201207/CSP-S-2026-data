#include <bits/stdc++.h>
using namespace std;
long long d,n;
char c;
string s;
bool hws(string s){
	for (int i=0,j=s.size()-1;i<=s.size()/2,j>=s.size()/2;i++,j--){
		if (s[i]!=s[j]){
			return false;
		}
		return true;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--){
		cin>>d>>c;
		for (int i=1;i<=d;i++){
			s+=c;
		}
	}
	if (hws(s)){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for (int i=0,j=s.size()-1;i<=s.size()/2,j>=s.size()/2;i++,j--){
		if (s[i]!=s[j]){
			s[j]=s[i];
			cnt++;
		}
		
	}
	cout<<cnt;
	return 0;
}