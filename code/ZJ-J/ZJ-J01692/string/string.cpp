#include<bits/stdc++.h>
using namespace std;
int len, n, k;
long long a[200001], minn, num; 
char c[200001], cc;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i] >> c[i], len += a[i] % 2, len %= 2;
	if(len == 1){
	    k = 1;
	    while(n > k){
	    	if(a[k] > a[n]){
	    		if(c[k] != c[n]) {
	    			num += a[n];
					a[k] -= a[n];
					n --;
				}
	    		else{
	    			a[k] -= a[n];
					n --;
				} 
			} 
			else if(a[k] == a[n]){
	    		if(c[k] != c[n]){
	    			num += a[k];
					k ++;
					n --;
				} 
	    		else{
	    			k ++;
					n --;
				}
			} 
			else if(a[k] < a[n]){
	    		if(c[k] != c[n]){
	    			a[n] -= a[k];
					num += a[k];
					k ++;
				} 
	    		else{
	    			a[n] -= a[k];
					k ++;
				} 
			} 
		}
	}
	else {
		k = 1;
	    while(n > k){
	    	if(a[k] > a[n]){
	    		if(c[k] != c[n]) {
	    			num += a[n];
					a[k] -= a[n];
					n --;
				}
	    		else{
	    			a[k] -= a[n];
					n --;
				} 
			} 
			else if(a[k] == a[n]){
	    		if(c[k] != c[n]){
	    			num += a[k];
					k ++;
					n --;
				} 
	    		else{
	    			k ++;
					n --;
				}
			} 
			else if(a[k] < a[n]){
	    		if(c[k] != c[n]){
	    			a[n] -= a[k];
					num += a[k];
					k ++;
				} 
	    		else{
	    			a[n] -= a[k];
					k ++;
				} 
			} 
		}
	}
	cout << num;
	return 0;
} 
