#include<bits/stdc++.h>
using namespace std;
int check(int a,int b){
	string a2,b2;
	while(a){
		a2 = char(a % 2 - int('0'))+ a2;
		a /= 2;
	}
	while(b){
		b2 = char(b % 2 - int('0')) + b2;
		b /= 2;
	}
	string c;
	for (int i = min(a2.size(),b2.size()) - 1;i >= 0;i--){
		if (a2[i] == b2[i]){
			c += '1';
		}
		else{
			c += '0';
		}
	}
//	cout << c << endl;
	int d = 0;
	for(int i = 0;i < c.size();i++){
		d += pow(2,i);
	}
//	cout << d << endl;
	return d;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	int a[n];
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	int max1 = -1;
	for (int i = 0;i < n;i++){
		for (int j = i + 1;j < n;j++){
			cout << a[i] << " " << a[j] << endl;
			int ans1 = check(a[i],a[j]);
//			cout << ans1 << endl;
			max1 = max(max1,ans1);
//			cout << max1;
		}
	} 
	cout << max1;
	return 0;
}
