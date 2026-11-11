#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fr front
#define fi first
#define se second
#define i64 long long
const int N=5e5+5;
const int inf=0x3f3f3f3f;
int n,m;
int a[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
