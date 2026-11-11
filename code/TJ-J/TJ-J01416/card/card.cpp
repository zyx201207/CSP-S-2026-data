#include<bits/stdc++.h>
using namespace std;
long long s[300005];
int main(){
	freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			cin >> s[i];
		}
	}
	int crow;
	if(crow%2==1){
		cout << n << " ";
	}
	else{
		cout << m << " ";
	}
	for(long long i=1;i<=n;i++){
		int txm;
		cout << s[crow/txm];
	}
	return 0;
}
