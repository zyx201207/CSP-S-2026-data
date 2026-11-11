#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2*1e5+5;
ll n;
//struct node{
//	ll l;
//	char s;
//};
string s;
//vector <node> v;
char c;
ll a,ans,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a >> c;
		for(int i = 1;i <= a;++i){
			s += c; 
		}
		len += a;
		//v.push_back({a,c});
	}
	for(int i = 0;i < len/2;++i){
		if(s[i] != s[len-i-1]){
			ans++;
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

