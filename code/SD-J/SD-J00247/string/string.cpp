#include<iostream>
#include<cmath>
#include<string>
#define ll long long
using namespace std;

ll n , ans ,x;
string s;
char c;

int main(){
	freopen("string.in", "r" ,stdin);
	freopen("string.out", "w" ,stdout);
	cin >> n;
	for(int i=1; i<=n ; i++) {
		cin >> x >> c;
		for(int j=1; j<=x ; j++) s+=c;
	}
	for(int i=0; i<(ll)s.size() ; i++) {
		if( i>=(ll)s.size()-i-1 ) break;
		if( s[i] != s[(ll)s.size()-i-1] ) ans++;
	}
	cout << ans;
	return 0;
}
