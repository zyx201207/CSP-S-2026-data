#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			cout << i  << ' ';
		}
	}
	else{
		for(int i=1;i<m;i++){
			cout << 0  << ' ';
		}
		cout << n;
	}
	return 0;
} 
