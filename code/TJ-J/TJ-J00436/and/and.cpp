#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m == 1){
		cout << 0;
	}
	int h=a[0];
	if(m == n){
		for(int i=1;i<n;i++){
			h = a[i] & h;
		}
		cout << h;
	}
	
	return 0;
}
