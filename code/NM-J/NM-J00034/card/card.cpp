#include <bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]][0]){
				for(int k=b[a[j]][0];k<j;k++){
					b[a[k]][1]--;b[a[k]][0]=0;
				}
			}
			b[a[j]][1]++;b[a[j]][0]=j;
		}
		for(int j=1;j<=m;j++){
			b[j][0]=0;
		}
	}
	for(int i=1;i<=m;i++) cout << b[i][1]<<" ";
	
	
	return 0;
}
