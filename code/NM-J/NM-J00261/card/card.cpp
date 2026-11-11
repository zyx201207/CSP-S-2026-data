#include <bits/stdc++.h>
using namespace std;

	long long int n,m,k[500005],km[300005],km1[500005],km2[300005],km3[500005];

int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
	cin >> k[i];
	}
	int a = 0;
	for(int i = 0;i<=n;i++){
		a = 1;
		for(int j = 1;a+i<=n;j++){
			a++;
			if(km2[k[i+a]]==0){
				km1[j] = k[i+a];
				km2[k[i+a]] = 1;
				km3[k[i+a]] = j;			
			}else{
				km2[k[i+a]] = 0;
				j = km3[k[i+a]];
				km3[k[i+a]] = j;
				}
		}
		
		for(int j = 1;j<=a+i;j++){
			km[km1[j]]++;
		}
	}
		for(int j = 1;j<=m;j++){
			cout << km[j] << " ";
		}
	return 0;
	}

