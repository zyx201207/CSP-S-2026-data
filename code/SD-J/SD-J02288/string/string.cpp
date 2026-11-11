#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, a, L=0, ans=0;
	long long t=1;
	string s;
	char z;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a;
		cin >> z; 
		L += a;
		for(int j=1;j<=a;j++){
			s[t] = z;
			t++;
		} 	
	}
	for(int i=1;i<=L;i++){
		if(s[i]-'0' != s[L+1-i]-'0'){
			ans++;
			s[L+1-i] = s[i];
		}
	}
	cout << ans<<endl;
	return 0;
}
