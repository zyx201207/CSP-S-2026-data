#include<bits/stdc++.h>
using namespace std;
long long n;
long long a,sum,ans;
string c;
string s = ""; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> c;
		for(int i = 1; i <= a; i++) s+=c;
		sum += a;
	}
	sum-=1;
	for(int i = 0; i <= sum / 2; i++){
		if(s[i] != s[sum-i]){
			ans ++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
