#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int a[N];
#define ll long long 
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	ll n,m,sum =0;
	cin >> n >> m;
	ll ans = -1;
	for(int i = 0;i<n;i++){
		cin >> a[i];
}
	for(int p = 1;p<=m;p++){
	for(int i = 0;i <n;i++){
	for(int j = i+1;j <n;j++){ 
		if(a[j] == a[i]){
			if(a[j] == p) sum ++,i--;
			if(a[i] == p) sum ++;
		}else{
			if(a[i] == p) sum++;
		}
	}
}cout << sum << " "; 
sum =0;
}
	return 0;
}
