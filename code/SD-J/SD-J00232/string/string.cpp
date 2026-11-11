#include <bits/stdc++.h>
using namespace std; 
int n;
long long a[200005],ans;
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i<=n;i++){
    	cin >> a[i] >> s[i];
	}
	int j = n;
	for (int i = 1;i < j;){
		if (a[i] == a[j]){
			if (s[i][0] != s[j][0]) ans += a[j];
			i++;
			j++; 
		}
		else if (a[i] > a[j]){
			if (s[i][0] != s[j][0]) ans += a[j];
			long long sum = a[j];
			while(sum <= a[i]){
				j++;
				sum+=a[j];
				if (s[j] != s[i]){
					ans += a[j];
				}
			}
			a[j] = sum-a[i];
			ans -= a[j];
			i++;
		}
		else if (a[i] < a[j]){
			if (s[i][0] != s[j][0]) ans += a[i];
			long long sum = a[i];
			while(sum <= a[j]){
				j++;
				sum+=a[i];
				if (s[i] != s[j]){
					ans += a[i];
				}
			}
			a[i] = sum-a[j];
			ans -= a[i];
			j++;
		}
	}
	cout << ans;
}
