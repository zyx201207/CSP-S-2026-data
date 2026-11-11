#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define ll long long
ll n,a1=0,a2=0;
ll a[N];
char s[N];
ll num = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
	}
	for(int i = 1; i <= n; i++){
		if(1 + a1 == n - a2){
			cout <<  num << endl;
			return 0;
		}
		if(s[1 + a1] != s[n - a2]){
			if(a[1 + a1] > a[n - a2]){
				num += a[n - a2];
				a[1 + a1] = a[1 + a1] - a[n - a2];
				a2 ++;
			}else if(a[1 + a1] < a[n - a2]){
				num += a[1 + a1];
				a[n - a2] = a[n - a2] - a[1 + a1];
				a1 ++;
			}else{
				num += a[n - a2];
				if(n - a2 - 1 == 1 + a1){
					cout << num << endl;
					return 0;
				}
				a1++;
				a2++;
			}
		}else{
			if(a[1 + a1] > a[n - a2]){
				a[1 + a1] = a[1 + a1] - a[n - a2];
				a2 ++;
			}else if(a[1 + a1] < a[n - a2]){
				a[n -a2] = a[n - a2] - a[1 + a1];
				a1 ++;
			}else{
			
				if(n - a2 - 1 == 1 + a1){
					cout << num << endl;
					return 0;
				}
				a1++;
				a2++;
			}
		}
	}
	return 0; 
}
