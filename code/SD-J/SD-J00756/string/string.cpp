#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[int(1e5*2)+3] ;
char b[int(1e5*2)+3];
int main() {
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll cnt = 0;
	cin >> n;
	bool e = 1;
	int k = n
	for(int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];
		if(i > 1 && b[i] == b[i - 1]  ){
			a[i-1] += a[i];
			n--;
			a[i] = 0;
			
			i--;	
		}
	}
	
	for(int i = 1; i < n; i++) {
		if(b[i] != b[i - 1]){
			e = 0;
		}
		
	}

	if (e){
		cout <<0;
		return 1;
	}
	for(int i = 0; i < n; i++) {
		cout << a[n] << " " << b[n]<< endl;
	}
	if(1){
		int t = n/2;
		for(int i = 0; i < t; i++) {
			if(a[i]!=a[n-1-i]&&b[i]==b[n-1-i]){
				cnt += abs(a[i]-a[n-1-i]);
			
			}else if(a[i]==a[n-1-i]&&b[i]!=b[n-1-i]){
				cnt += a[i];
			
			}else{
				cnt += max(a[i],a[n-1-i]);
			}
		}
		cout << cnt; 
	} 
	
	
	
	
	return 0;
}

