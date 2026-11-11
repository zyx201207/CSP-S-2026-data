#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005],nex[500005],f[500005],cnt[500005],pre[500005],la[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(la[a[i]]!=0){
			nex[la[a[i]]]=i;
		}
		la[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		if(nex[i]==0){
			pre[i]=i+1;
			f[i]=a[i];
		}
		else{
			pre[i]=nex[i];
		}
		cnt[i]++;
	}
	for(int i=1;i<=n;i++){
		//cout << cnt[i] << " " << nex[i] << " " << f[i] << " " << pre[i] << endl;
		cnt[pre[i]]+=cnt[i];
		ans[f[i]]+=cnt[i];
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
}