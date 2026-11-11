#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pii pair<int,int>
#define vec vector
#define For(i,st,ed) for(int i=st;i<=ed;i++)
using namespace std;
const int N=2e5+3;
const int M=1e5+3;
int a[N],lst[M],n,m;
void solve(){
	cin >> n >> m;
	For(i,1,n){
		cin >> a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<lst[i]<<" ";
	}
}
signed main(){
	IOS;
	freopen("card.in", "r",stdin);
	freopen("card.out","w",stdout);
    //int t;cin >> t;while(t--)
    solve();
    return 0;
}
