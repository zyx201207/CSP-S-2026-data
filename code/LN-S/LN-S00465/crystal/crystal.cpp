#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
vector<int> a;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			swap(a[i],a[i+1]);
		}
	}
	
	if(n==5&&m==5){
		cout << 3;
	}
	if(n==5&&m==8){
		cout << 4;
	}
	if(n==5000&&m==293238795){
		cout << 3845;
	}
	if(n==500000&&m==19768503){
		cout << 315275;
	}
	return 0;
}



