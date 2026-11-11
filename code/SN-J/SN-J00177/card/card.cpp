#include <bits/stdc++.h>
using namespace std;
long long  n , m , a[500005] , s[300005] , b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n ; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n ; i ++){
		for(int j = 0; j < n ; j ++){
			b[j] = a[j];
		}
		for(int j = i; j < n -1; j ++){
			if(b[j]==b[j+1]){
				b[j] = 0;
			}
		}
		for(int z = 1; z <= m ; z ++){
			for(int j = i; j < n ; j ++){
				if(b[j] == z){
					s[z] ++;
				} 
			}
		}		
	}
	for(int i = 1; i <= m ; i ++){
		cout << s[i] << ' ';
	}
	
	//Ï¹´òÒ»ÏÂA°É 
	return 0;
} 
