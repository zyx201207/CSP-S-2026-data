#include<bits/stdc++.h>
#define ll long long
//rp++
/*
two point!!!
*/
using namespace std;

int n;
ll cnt;
struct node{
	ll va;
	char ch;
};
vector<node> x, y;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		ll a;
		char c;
		cin >> a >> c;
		x.push_back({a, c});
	}
	for(int i = x.size() - 1;i >= 0;i --)
		y.push_back(x[i]);
	ll xi = 0, yi = 0;
	while(xi != x.size() && yi != y.size()){
		if(x[xi].va > y[yi].va){
			if(x[xi].ch != y[yi].ch) cnt += y[yi].va;
			x[xi].va -= y[yi].va;
			yi ++;
		} else if(x[xi].va < y[yi].va){
			if(x[xi].ch != y[yi].ch) cnt += x[xi].va;
			y[yi].va -= x[xi].va;
			xi ++;
		} else {
			if(x[xi].ch != y[yi].ch) cnt += x[xi].va;
			xi ++, yi ++;
		}
	}
	cout << cnt / 2; //remember!!! / 2
	return 0;
}

