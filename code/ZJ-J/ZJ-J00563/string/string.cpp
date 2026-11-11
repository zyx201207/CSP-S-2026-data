#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char s[200010];
int sum;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
		sum += a[i];
	}
	int x = 0;
	int i = 1,j = n;
	while(i < j){
		if(a[i] < a[j]){
			if(s[i] != s[j]){
				x += a[i];
				a[j] -= a[i];
				a[i] = 0;
			}
			else{
				a[j] -= a[i];
				a[i] = 0;
			}
		}
		else{
			if(s[i] != s[j]){
				x += a[j];
				a[i] -= a[j];
				a[j] = 0;
			}
			else{
				a[i] -= a[j];
				a[j] = 0;
			}
		}
		if(a[j] == 0)
			j--;
		if(a[i] == 0)
			i++;
	}
	cout << x;
	return 0;
}