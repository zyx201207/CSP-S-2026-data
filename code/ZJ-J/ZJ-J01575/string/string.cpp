#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b;
string s;
char c;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//I can only get some parts of score...awa
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>c;
		while(b--)s+=c;
	}
	int sum = 0;
	for (int i=0;i<s.length()/2; i++){
		if(s[i]!=s[s.length()-1-i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
