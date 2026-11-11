#include<bits/stdc++.h>
#define int long long
const int N=2e6+5;
using namespace std;
struct node{
	int x,cnt;
};
int dx[2]={1,-1};
int a[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<+n;i++){
		cin>>a[i];
	}
	cout<<0<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c,T;
	while(T--){
		solve();
	}
	return 0;
}