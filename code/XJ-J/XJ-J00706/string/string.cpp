#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int b,ans,len,kkk;
char k;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b;
		cin >> k;
		for(int j=1;j<=b;j++) s+=k;
	}
	len=s.size();
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) kkk++;
	}
	cout << kkk;
}
