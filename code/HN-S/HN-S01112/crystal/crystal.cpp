#include<bits/stdc++.h>
using namespace std;
int n,m;
int an[500000];
#define int long long
bool check(int n){
	int x = an[n];
	int sum = 0;
	for(int i = 1;i <= n;i++){
		sum += x - an[i];
	}
	return sum <= m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>an[i];
	}
	sort(an + 1,an + n + 1);
	int l = 1,r = n;
	int mid;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid)){
			l = mid;
		}
		else r = mid - 1;
		if(l == r - 1) break;
	}
	if(check(l + 1)) cout<<l + 1;
	else cout<<l;
	return 0;
} 
