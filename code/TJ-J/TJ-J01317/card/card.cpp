#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int y=1;
	while(y<=m){
		for(int j=n-1;j>=0;j--){
			if(a[j]==y){
				if(a[j-1]==a[j+1]){
					cout << j << " ";}
				else{
					cout << j+1 << " ";}
				break;
			}
			
		}
		y++;
	}
	return 0;
}
