#include <bits/stdc++.h>
using namespace std;

int a[200005], n;
long long ans;
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> s[i];
	}
	int i=1,j=n-i+1;
	while (i<j){
		int d=min(a[i], a[j]);
		if (s[i]!=s[j]) ans+=d;
		a[i]-=d, a[j]-=d;
		if (a[i]==0) i++;
		if (a[j]==0) j--;
	}
	cout << ans << endl;
	return 0;
}
