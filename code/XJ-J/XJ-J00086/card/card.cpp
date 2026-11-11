#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100006];
int sxd[10006][10006];
int sum;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int l = 1;l <= n;l++){
		for(int i = l;i <= n;i++){
			for(int j = l;j <= n;j++){
				if(a[i] == a[j]){
					i = j;
				}
				else{
					sxd[l][j] = a[j];
				}
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			if(sxd[i][j] == i){
				sum++;
			}
		}
		cout << sum << " ";
	}
	
	return 0;
}
