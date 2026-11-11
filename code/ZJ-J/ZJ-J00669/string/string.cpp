#include <bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("sting.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	int i = 1;
	int j = n;
	while(i < j){
		if(a[i] < a[j]){
			if(b[i] == b[j]){
				a[j] -= a[i];
				i++;
			}
			else{
				ans+=a[i];
				a[j] -= a[i];
				i++;
			}
		}
		else if(a[i] > a[j]){
			if(b[i] == b[j]){
				a[i] -= a[j];
				j--;
			}
			else{
				ans += a[j];
				a[i] = a[i] - a[j];
				j--;
			}
		}
		else if(a[i] == a[j]){
			if(b[i] == b[j]){
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;
			}
			else{
				ans+=a[i];
				a[i] = 0;
				a[j] = 0;
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
