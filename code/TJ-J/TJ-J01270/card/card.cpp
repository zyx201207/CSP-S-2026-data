#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m ,ans = 0;
	cin >> n >> m;
	for(int  i = 0;i < n; i++){
		cin >> a[i];
	}
	for(int i = 0;i < n; i++){
		for(int j = 0; j < m;j++){
			if(a[j] == a[i]){
				if(a[j+1]-a[j-1] == 1 ){
					cout << i;
				}
				a[i] = a[i+1];
				condition;
			}
		}
	}
	return 0;
}
