#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll cnt,total;
ll mid;
vector<char> d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		ll now;
		char kk;
		cin >> now >> kk;
		cnt+=now;
		for(ll j=1;j<=now;j++){
			d.push_back(kk);
		}
	}
	mid = cnt/2;
	for(ll i=0;i<mid;i++){
		if(d[i]!=d[cnt-i-1])
			total++;
	}
	cout << total;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
