#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N],c[N];
map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		b[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			while(b[j]){
				j=b[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}


