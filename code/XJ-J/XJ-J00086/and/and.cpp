#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
string a2[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin >> n >>m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int big = 0;
	for(int i = 1;i<= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i] && a[j] >= big){
				big = a[i];
			}
		}
	}
	cout << big;
	
	return 0;
}
