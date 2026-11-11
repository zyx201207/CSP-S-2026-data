#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500010],x[500010],ans[500010],cnt[500010],kuato[500010];
int cc[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[a[i]]=i;
	}
	int to=n+1;
	for(int i=n;i>=1;i--){
		cnt[a[i]]++;
		if(cnt[a[i]]==1){
			kuato[i]=to;
		}else{
			to=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j){
			if(kuato[j]!=0)j=kuato[j];
			else{
				ans[j]--;
				ans[x[a[j]]]++;
				j=x[a[j]];
			}
		}
	}
	int t=0;
	for(int i=1;i<=n;i++){
		t+=ans[i];
		cc[a[i]]+=t+i;
	}
	for(int i=1;i<=m;i++){
		cout<<cc[i]<<" ";
	}
	return 0;
}
