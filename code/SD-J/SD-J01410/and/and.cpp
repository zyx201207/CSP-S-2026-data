#include<bits/stdc++.h>
using namespace std;
/*====================*/
const int N=2e5+10;
const int M=1e5+10;
/*====================*/
const int INF=0x3f3f3f3f;
const int MOD=998244353;
/*====================*/
int n,a[N],m;
vector<int> b,c;
/*====================*/
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b.push_back(a[i]);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		for(int j=0;j<b.size();j++){
			int x=b[j];
			if(x&(1<<i))c.push_back(x);
		}
		if(c.size()>=m){
			ans+=(1<<i);
			b=c;
		}
		c.clear();
	}
	cout<<ans;
}
/*====================*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}

