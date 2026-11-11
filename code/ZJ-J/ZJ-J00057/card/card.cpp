#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+7;
const int M=3e5+7;

int n,m;
int a[N];

int lst[M];
int ans[N];


signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);

	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=max(lst[a[i]],i);
	}

	for(int i=1;i<=n;i++){
		int pos=i;
		while(pos<=n){
			++ans[a[pos]];
			if(pos!=lst[a[pos]]){
				pos=lst[a[pos]];
				--ans[a[pos]];
			}
			else{
				++pos;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
