#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2e5 + 5;
ll n;
ll len[M];
char let[M];
ll res;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	ll ls = 1, rs = n;
	for (ll i = 1; i <= n; i++ ){
		cin >> len[i];
		cin >> let[i];
	}
	while (ls < rs){
		while (rs > ls){
			if (len[rs] > len[ls]){
				if (let[ls] != let[rs]) res += len[ls];
				len[rs] -= len[ls];
				break;
			}
			else if (len[rs] == len[ls]){
				if (let[ls] != let[rs]) res += len[ls];
				rs--;
				break;
			}
			else{
				if (let[ls] != let[rs]) res += len[rs];
				len[ls] -= len[rs];
				rs--;
			}
		}
		ls++;
	}
	cout << res << '\n';
	return 0;
} 
