#include<bits/stdc++.h>
using namespace std;
string s,c;
int a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		for(int j = 1; j <= a[i]; j++){
			s += c[i];
		}
	}int l = s.length()-1,f = 0;
	for(int i = 0; i <= l; i++){
		for(int j = l; j >= 0; j--){
			if(i == j){
				break;
			}if(s[i] == s[j]){
				f++;
			}else{
				f = 0;
				break;
			}
		}
	}if(f != 0){
		cout << "0\n";
		return 0; 
	}else{
		if((l + 1) / 2 == 0){
			cout << (l + 1) / 2;
		}else{
			cout << l / 2;
		}
	}
	return 0;
}
