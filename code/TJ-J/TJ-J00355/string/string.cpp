#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long sum,ans,a[N][3];
char s[N];
long long n,l,r;
void run(){
	long long lenr = a[r][2] - a[r][1] + 1;
	long long lp = sum + 1 - a[r][2];
	if(a[l][2] - lp + 1 >= lenr){
		if(s[l] != s[r]) ans += lenr;
		if(a[l][2] - lp + 1 == lenr) r--,l++;
		else r--;
		return;
	}
	while(lenr > 0 && r >= l + 1){
		if(s[l] != s[r]) ans += (a[l][2] - lp + 1);
		lp = a[l][2] + 1;
		l++;
		if(a[l][2] - lp + 1 >= lenr){
			if(s[l] != s[r]) ans += lenr;
		    if(a[l][2] - lp + 1 == lenr) r--,l++;
	 	    else r--;
		    return;
		}
		lenr -= (a[l][2] - lp + 1);
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i][0] >> s[i];
		a[i][1] = sum + 1,a[i][2] = a[i][1] + a[i][0] - 1;
		sum = a[i][2];
	}
	l = 1,r = n;
	while(r >= l + 1){
		run();
	}
	cout << ans << endl;
	return 0;
}
