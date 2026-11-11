#include <bits/stdc++.h>

using namespace std;
long ans=-1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n;
	cin >> n;
	
	for (long i=1;i<=n;i++){
		long num;
		string s;
		cin >> num >> s;
		ans = max(ans,num);
		}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}

