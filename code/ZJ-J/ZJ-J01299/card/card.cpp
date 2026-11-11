#include<bits/stdc++.h>
using namespace std;
int la[300010];
int lb[300010];
int lc[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >>m;
	int t=0;
	int lsw;
	for(int i=1;i<=n;i++){
		cin >> lsw;
		lc[i]=lsw;
		la[lsw]++;
		if(i==n){
			la[lsw]=n;
		}
	}
	for(int i=1;i<=m;i++){
		cout << la[i] << " ";
	}
	cout << endl;
	for(int i=n-1;i>=1;i--){
		lb[lc[i]]++;
		if(lb[lc[i]]!=1){  break;}
		for(int j=i+1;j<n;j++){
			cout << i << " " << lc[j] << endl;
			la[lc[j]]++; 
		}
	}
	for(int i=1;i<=m;i++){
		cout << la[i] << " ";
	}
	return 0;
}

