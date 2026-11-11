#include<bits/stdc++.h>
#define Endl endl
#define endl "\n"
#define For for
using namespace std;
int n,min_n = INT_MAX,a,ans;
char r[10010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	if(n == 1){
		cout << 0 <<endl;
		return 0;
	}
	if(n == 2){
		bool is = true;
		for(int i = 1;i <= n;i++){
			cin >> a >> r[i];
			if(r[i] != r[i-1] && i != 1){
				is = false;
			}
			min_n = min(min_n,a);
		}
		if(is){
			cout << 0 <<endl;
		}else{
			cout << min_n <<endl;
		}
		return 0;
	}
	string s = "";
	for(int i = 1;i <= n;i++){
		int a;
		char r;
		cin >> a >> r;
		for(int i = 1;i <= a;i++){
			s += r;
		}
	}
	int len = s.size();
	for(int i = 0;i < len/2;i++){
		if(s[i] != s[len+1-i]){
			ans++;
			s[len+1-i] = s[i];
		}
	}
	cout << ans <<endl;
	
	return 0;
}
//string 4
