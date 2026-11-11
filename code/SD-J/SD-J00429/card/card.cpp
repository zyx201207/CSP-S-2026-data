#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int a[N],ans[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) cnt[j]=0;
		for (int j=i;j<=n;j++){
			if (cnt[a[j]]){
				for (int k=cnt[a[j]];k<=j;k++) cnt[a[k]]=0;
			}
			cnt[a[j]]=j;
		}
		for (int j=1;j<=m;j++){
			if (cnt[j]) ans[j]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

