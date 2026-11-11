#include<bits/stdc++.h>
#include<cstdio>
#include<string>
int n, m, nm = 1, a[600009]/*输入数组*/,b[600009]/*输出数组*/,/*c[600009],*/ play[600009], tnt, ;
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i];
	}
	for(int i = n; i >= 1;i--){
		if(a[i] == a[n]){
			tnt = i;
		}
	}
	while(nm != n){
		for(int i = nm; i <= n i++){
			int c = play[i], d = 1;
			for(int j = nm; j <= n;j++){
				if(play[j] == c){
					d = 0;
					break;
				}
			}
			if(d == 1)
			{
				b[play[c]]++;
			}
		}
		nm++;
	}
	for(int i = 1; i <= n; i++){
		cout << b[i] << ' ';
	}
	return 0;
}
