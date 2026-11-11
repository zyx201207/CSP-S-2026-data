#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    int MAX = 2005;
    int a, m = 0;
    char b;
    cin >> n;
    vector<char> s(n*MAX, 0), s_(n+5,0);
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		for(int j = 0; j < a; j++){
			s[m+j] = b;
			s_[n*MAX-m-j] = b;
		} m += a;
	}
	int cnt = 0;
	for(int p = 0; p < n*MAX; p++){
		if(s[p] != s_[p]){
		cnt++;
		}
	}
	bool t = cnt % 2;
	cnt = cnt / 2;
	if(t){
		cnt++;
	}
	cout << cnt;
    return 0;
}

