#include<bits/stdc++.h>
using namespace std;
#define ll long long
string sa,sb,sc;
ll sum =0;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	ll n;
	cin >> n;
	getline(cin,sa);
	getline(cin,sb);
	if(n == 1) cout << "0";
	for(int i = 0;i<n;i+=2){
		if(sa[1] == sb[1]){
			cout << "0";
		}else{
			cout << "1"; 
		}
	}
	return 0;
}
