#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[300005];
	cin >> n >> m;
	for(int i=0;i<=m;i++){
		cin >> a[i];
	}
	while(n<=0){
		for(int i=1;i<=m;i++){
			if(a[i]==a[1]){
				for(int j=2;j<=i;j++){
					a[j] == 0;
				}
			}
			cout << a[i]; 
		}
		
		n--;
	}
	return 0;
} 
