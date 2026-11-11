#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt[300005],f[500005];
	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	bool ta=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) ta=false;
	}
	if(ta){
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1],cout<<cnt[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				f[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[j]==0) cnt[a[j]]++;
			else j=f[j]-1;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
