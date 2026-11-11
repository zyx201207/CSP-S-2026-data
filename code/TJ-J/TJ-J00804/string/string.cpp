#include<bits/stdc++.h>
using namespace std;
long long n,a,l,r,cnt=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a >> c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout << cnt;
	return 0;
}
