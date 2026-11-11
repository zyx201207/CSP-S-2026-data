#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n],b[n];
	long long cnt = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		char c;
		cin >> c;
		b[i] = c-'a';
	}
	long long l = 0,r = n-1;
	while(l < r){
		if(b[l] == b[r]){
			if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}else if(a[l] == a[r]){
				l++;
				r--;
			}else{
				a[l] -= a[r];
				r--;
			}
		}else{
			if(a[l] < a[r]){
				a[r] -= a[l];
				cnt += a[l];
				l++;
			}else if(a[l] == a[r]){
				cnt += a[l];
				l++;
				r--;
			}else{
				a[l] -= a[r];
				cnt += a[r];
				r--;
			}
		}
	}
	cout << cnt;
	return 0;
} 
