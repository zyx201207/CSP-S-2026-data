#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=i;
		int f[300005]={0};
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0)
			f[a[j]]=1;
			else
			t=j;
		}
		for(int j=t;j<=n;j++){
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]!=0)
		cout<<cnt[i]<<" ";
	}
	return 0;
}