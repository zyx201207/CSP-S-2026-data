#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	char op;
	ll num;
}A[210000];
vector<node> a,b;
int main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	ll l = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i].num >> A[i].op;
		l += A[i].num;
	}
	ll now = 0;
	for(int i = 1 ; i <= n ; i++){
		if(now<=l/2&&now+A[i].num>l/2){
			a.push_back({A[i].op,l/2-now});
			if(now+A[i].num-l/2-(l%2)>0)
				b.push_back({A[i].op,now+A[i].num-l/2-(l%2)});
			now += A[i].num;
			continue;
		}
		now += A[i].num;
		if(now>l/2)
			b.push_back(A[i]);
		else
			a.push_back(A[i]);
	}
	reverse(b.begin(),b.end());
	int j = 0;
	ll ans = 0;
	b.push_back({0,0});
	b.push_back({0,0});
	for(int i = 0 ; i < a.size() ;){
		if(a[i].num>b[j].num){
			if(a[i].op!=b[j].op) ans += b[j].num;
			a[i].num -= b[j].num;
			j++;
		}
		else if(a[i].num<b[j].num){
			if(a[i].op!=b[j].op) ans += a[i].num;
			b[j].num -= a[i].num;
			i++;
		}
		else if(a[i].num==b[j].num){
			if(a[i].op!=b[j].op) ans += a[i].num; 
			i++;j++;
		}
	}
	cout << ans;
	return 0;
}
//rp++
