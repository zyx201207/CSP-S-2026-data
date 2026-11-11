#include<bits/stdc++.h>
using namespace std;
int n,s,tot;
int l,r;
char c;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s >> c;
		for(int i = 1;i <= s;i++){
			ss+=c;
		}
	}
	r=int(ss.size()-1);
	for(int l;l <= r;l++,r--){
		if(ss[l]!=ss[r]){
			tot++;
		}
	}
	cout << tot;
	return 0;
} 
