#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m == 1){
		int t = 0;
		for(int i = 0;i < n;i++){
			int y;
			cin >> y;
			if(y > t){
				t = y;
			}
		}
		cout << t;
	    return 0;
	}else if(n == m){
		int j = 0;
		int a[10000];
		for(int i = 0;i < n;i++){
			cin >> a[i];
			if(i != 0){
				j = j & a[i];
			}else{
				j = a[i];
			}
		}
		cout << j;
	    return 0;
	}else if(m == n-1){
		int v = 0,c = 0;
		int k[10000];
		for(int i = 0;i < n;i++){
			cin >> k[i];
			if(i != 1 && i != 0){
				v = v & k[i];
			}else{
				v = k[i];
			}
		}
		for(int i = 0;i < n-1;i++){
			if(i != 0){
				c = c & k[i];
			}else{
				c = k[i];			
			}
	 	}
	 	cout << max(v,c);
	 	return 0;
	}
	return 0;
}
