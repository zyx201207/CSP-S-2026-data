#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,x,cnt,mid,ans;
char ch;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x >> ch;
		cnt += x;
		for(int i=0;i<x;i++){
			s += ch;
		}
	}
	s = '0'+s;
	mid = ceil(cnt/2.0);
	for(int i=1;i<=mid;i++){
		if(s[i]!=s[cnt-i+1]){
			ans ++;
//			cout << i << endl;
		}
	}
	cout << ans;
	return 0;
}
