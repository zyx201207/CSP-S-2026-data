#include <bits/stdc++.h>
using namespace std;

int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin>>n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		cin >> b[i];
	}
	
	long long c=0;
	int l=1,r=n;
	while (l<r){
		if (b[l]==b[r]){
			if (a[l]==a[r]){
				l++; r--;
				continue;
			}
			else if (a[l]<a[r]){
				a[r]-=a[l]; l++;
			}
			else {
				a[l]-=a[r]; r--;
			}
		}
		else{
			if (a[l]==a[r]){
				c += a[l];
				l++; r--;
				continue;
			}
			else if (a[l]<a[r]){
				c += a[l];
				a[r]-=a[l]; l++;
			}
			else {
				c+= a[r];
				a[l]-=a[r]; r--;
			}
		}	
	}
	
	cout << c;
	return 0;
}