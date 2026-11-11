#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1){
			b[1] = i;
		}else if(a[i] == 2){
			b[2] = i;
			
		}else if(a[i] == 3){
			b[3] = i;
		}else if(a[i] == 4){
			b[4] = i;
		}
	}
	for(int i = 1;i <= m; i++){
		cout << b[i] << " ";
	}
	return 0; 
}
