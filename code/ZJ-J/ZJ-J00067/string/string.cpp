#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005] = {'.'};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,_max = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		_max = max(_max,a[i]);
	}
	if(_max <= 1){
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(c[i] != c[n-i+1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n <= 2000&&_max <= 50){
		string s = "";
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= a[i];j++){
				s += c[i];
			}
		}
		int ans = 0;
		for(int i = 0;i+i <= (int)s.size()-2;i++){
			if(s[i] != s[s.size()-i-1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	c[n+1] = c[1];
	long long lsum = 0,rsum = 0,ans = 0;
	for(int i = 1,j = n;i <= j;i++){
		lsum += a[i];
		int tmp = min(a[j+1],a[i]);
		a[j+1] -= tmp,a[i] -= tmp;
		if(c[i] != c[j+1]){
			ans += tmp;
		}
		while(rsum < lsum&&j > i){
			rsum += a[j];
			int tmp = min(a[j],a[i]);
			a[j] -= tmp,a[i] -= tmp;
			if(c[j] != c[i]){
				ans += tmp;
			}
			j--;
		}
	}
	cout<<ans;
	return 0;
}
