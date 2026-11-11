#include<bits/stdc++.h>
using namespace std;
int a[200005],n,ans,r = 1,l;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	l = n;
	string s;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		for(int j= 1;j <= a[i];j++){
			s+=b[i];
		}
	}
	for(int i = 1;i <= n/1;i++){
		if(s[i] != s[n-i+1]){
			ans++;
		}
	}
	cout <<ans;
	return 0;
} 
