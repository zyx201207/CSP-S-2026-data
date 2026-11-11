#include <bits/stdc++.h>
using namespace std;
long long n,a,len,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >>c; 
		len+=a;
		while(a--){
			s+=c;
		}
	}
	long long len_2=len/2;
	for(int i=0;i<len_2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
