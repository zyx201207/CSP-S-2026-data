#include<bits/stdc++.h>
using namespace std;
int a[500100];
int z[300100];
int b[500100];
int n, m;
int s(int v){
	int c = 1;
	int x[300100] = {0};
	for(int i = v;i <= n;i++){
		if(x[a[i]] == 0){
			x[a[i]] = c;
			b[c] = a[i];
			c++;
		}else{
			if(x[a[i]] >= c){
				x[a[i]] = c;
				b[c] = a[i];
				c++;
			}else{
				c = x[a[i]] + 1;
			}
		}
	}
	for(int i = 1;i < c;i++){
		z[b[i]]++;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		s(i);
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
