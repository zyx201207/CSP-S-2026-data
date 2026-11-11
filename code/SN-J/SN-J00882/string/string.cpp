#include<bits/stdc++.h>
using namespace std;
string s,c;
int main(){
	freopen("string4.in","r",stdin);
	freopen("string4.out","w",stdout);
	long long a,n;
	long long ic = 0,cnt = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a >> c[i];
		for(int j = 1;j <= a;j++){
			s[ic] = c[i];
			ic++;
		}
	}
	long long si = s.size()/2+1;
	for(int i = 0;i < si;i++){
		if(s[i] != s[ic]){
			s[i] = s[ic];
			cnt++;
			ic--;
		}
	}
	cout << cnt;
	return 0;
}
