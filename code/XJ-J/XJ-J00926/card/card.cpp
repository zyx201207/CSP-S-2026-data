#include <bits/stdc++.h>
using namespace std;
int ant[300010];
int sum[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[500010];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			ant[k]=0;
		}
		for(int j=i;j<=n;j++){
			ant[a[j]]++;
			if(ant[a[j]]>1){
				for(int k=1;k<=m;k++){
					ant[k]=0;
				}
				ant[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(ant[j]!=0) sum[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}