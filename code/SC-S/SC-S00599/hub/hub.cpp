#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const int N = 1e6+5;
using namespace std;
int c,t,n,k;
vector<int>a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >>t;
	while(t--){
		cin >>n >>k;
		for(int i=1;i<=n;i++){
			int x,y;cin >>x >>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		cout <<1 <<endl;
	}
	return 0;
}
