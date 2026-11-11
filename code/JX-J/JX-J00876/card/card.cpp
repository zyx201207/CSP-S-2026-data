#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int cnt[300005];
bool vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) {
		cnt[a[1]]+=n;
		for(int i=1;i<n;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	return 0;
}
