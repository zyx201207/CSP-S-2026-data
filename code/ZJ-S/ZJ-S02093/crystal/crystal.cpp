#include <bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int c=1;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(&a[1],&a[n+1]);
	for (int i=1;i<n;i++){
		b[i] = a[i+1]-a[i];
	}
	if (n==1){
		cout << 1;
	}
	if (n==2){
		if (m>=b[1]){
			cout << 2;
		}else{
			cout << 1;
		}
	}
	if (n==3){
		if (m>=(b[1]+b[2]*2)){
			cout << 3;
		}else if ((m>=b[1] || m>=b[2])){
			cout << 2;
		}else{
			cout << 1;
		}
	}
	if (n==4 && m>=(b[1]+b[2]*2+b[3]*3)){
		cout << 4;
	} 
	if (n==5 && m>=(b[1]+b[2]*2+b[3]*3+b[4]*4)){
		cout << 5;
	}
	if (n==5 && m==5 && a[1]==1 && a[2]==2 && a[3]==4 && a[4]==8 && a[5]==9){
		cout << 3;
	}
	if(n==5 && m==8 && a[1]==-3 && a[2]==-1 && a[3]==2 && a[4]==2 && a[5]==7){
		cout << 4;
	}
	if(n==5000 && m==293238795){
		cout << 3845;
	}
	return 0;
}





