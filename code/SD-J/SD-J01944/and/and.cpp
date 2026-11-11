#include<bits/stdc++.h>
using namespace std;
int a[200010],s[201000];
int ad(int x,int y){
	if(x < y){
		return x;
	}else if(x == y){
		return x;
	}else{
		return y;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int l = 0,nn = n + 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		l ++;
		nn --;
		s[l] = ad(a[i],a[nn]);
	}long long mx = -1;
	for(int i = 1; i <= l; i++){
		if(mx < s[i]){
			mx = s[i];
		}
	}cout << mx;
//4 2
//3 15 12 12 
	return 0;
}
