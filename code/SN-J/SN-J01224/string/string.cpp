#include <bits/stdc++.h>
using namespace std;

int l;
int a[2*10*10*10*10*10+10]; string c[2*10*10*10*10*10+10];
int ans=2;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> c[i]; 
	}
	
	//先判断后两项 
	for(int i=0;i<n;i++){
		if(c[0]==c[i]) l++;
	}
	if(l=n){
		cout<<0;
		return 0;
	}
	l=0;
	//前两项
	for(int i=0;i<n;i++){
		if(a[0]=a[i]) l++;
	}

	for(int i=0;i<n;i++){
		if(c[i] != c[n-i]) ans++;
	}

	
	cout << ans;
	

	return 0;
}
