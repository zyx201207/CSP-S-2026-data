#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt,ans;
char c[200005],s[200005];
int huiwen(){
	int l=1,r=cnt;
	while(l<r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			ans++;
			return huiwen();
		}
		l++,r--;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s[++cnt]=c[i];
		}
	}
	cout << huiwen();
	return 0;
}
