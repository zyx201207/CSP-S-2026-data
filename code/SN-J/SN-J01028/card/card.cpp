#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int n,m,a[MAXN],ans[MAXM],tail[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(tail[a[i]]==0){
			tail[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int k=i;
		ans[a[i]]++;
		while(k<=n){
			k=tail[a[k]]+1;
			int hj=a[k];
			ans[hj]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m){
			cout<<ans[i];
			break;
		}
		cout<<ans[i]<<' ';
	}
	return 0;
}
