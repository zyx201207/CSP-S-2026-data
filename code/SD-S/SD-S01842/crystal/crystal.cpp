#include<bits/stdc++.h>
using namespace std;
const int maxn = 500050;
long long n,m,o,mt = 0,t = 0;
long long a[maxn] = {0},c[maxn] = {0};
//int getint(){
//	char mychar;
//	int myint;
//	mychar = getchar();
//	myint = mychar - '0';
//	return myint;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = a[i] - a[i - 1];
	}
	for(int i = 1;i <= n;i++){
		o = m;
		t = 0;
		for(int j = 1;j <= n;j++){
			if(a[i] >= a[j] && o >= a[i] - a[j]){
				o -= a[i] - a[j];
				t++;
//				cout << a[i] << " " << a[j] << "\n";
			}
		}
		if(mt <= t){
			mt = t;
		}
	}
	cout << mt;
	return 0;
} 
