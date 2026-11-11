#include <bits/stdc++.h>
using namespace std;
bool ok=1;
int n,m;
int a[500010],cnt[300005],kards[3010];
void cheat(){
	for(int i=1;i<=n;++i){
		for(int j=a[i];j<=m;++j){
			cnt[j]++;
		}
	}
	for(int i=1;i<=m;++i)cout<<cnt[i]<<' ';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1])ok=0;
	}
	if(ok){
		cheat();
	}else{
		for(int i=1;i<=n;++i){
			int cmt=0;
			for(int j=i;j<=n;++j){
				for(int k=1;k<=cmt;++k){
					if(kards[k]==a[j]){
						cmt=k-1;
						break;
					}
				}
				kards[++cmt]=a[j];
			}
			for(int j=1;j<=cmt;++j)cnt[kards[j]]++;
		}
		for(int i=1;i<=m;++i){
			cout<<cnt[i]<<' ';
		}
	}
	return 0;
}

