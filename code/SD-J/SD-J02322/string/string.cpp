#include<bits/stdc++.h>//×£ÎÒ¿ªÖÇ£¬ÓÀ²»±©Áã 
using namespace std;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s="";
	int n;
	cin >>n;
	if(n==1){
		cout <<0;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		int a;
		string b;
		cin >> a >>b;
		while(a--)s+=b; 
	}
	int len=s.size()/2;
	int lenn=s.size()-1;
	for(int i = 0;i<len;i++){
		if(s[i]!=s[lenn-i])cnt++;
	}
	cout << cnt;
	return 0;
}
