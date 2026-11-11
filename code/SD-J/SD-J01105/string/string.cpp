#include <bits/stdc++.h>
using namespace std;
string a[200005];
int b[200005];
int n;
int l,r;
unsigned long long cnt,need;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> b[i] >> a[i];
		cnt += b[i];
	}
	int l = 0,r = n - 1;
	while (cnt > 1){
		if (a[l] != a[r])need++;
		cnt -= 2;
		if (b[l] == 1)l++;
		else b[l]--;
		if (b[r] == 1)r--;
		else b[r]--;
	}
	cout << need;
}
