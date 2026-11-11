#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
int n,m,ma;
int a[maxn];
//int tr[maxn][2];
//int tot;
//void insert(int x){
//	int rt=0;
//	for(int k=30;k>=0;k--){
//		int num=((x>>k)&1);
//		if(!tr[rt][num]) tr[rt][num]=++tot;
//		rt=tr[rt][num], v[rt]++;
//	}
//}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i], ma=max(a[i],ma);
	cout<<ma;
}
