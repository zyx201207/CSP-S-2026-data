#include<bits/stdc++.h>
using namespace std;
char S[1*1024*1024*512];
long long n,a,ii,i,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> a;
		cin >> c;
		i = ii;
		ii += a;
		for(;i < ii;i++){
			S[i] = c;
		}
	}
	for(int k = 0;k < (ii / 2);k++){
		if(S[k] != S[ii - k - 1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
