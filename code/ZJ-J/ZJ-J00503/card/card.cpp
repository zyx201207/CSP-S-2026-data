#include<bits/stdc++.h>
using namespace std;
int a[500010],tp[300010],cnt[500010];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		tp[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		int l=i;
		while(l<n){
			cnt[a[l]]++;
			l=tp[a[l]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//while (1){
		solve();
	//}
	return 0;
}
