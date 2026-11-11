#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005],ans[300005],tong[300005],cnt[300005],gs[300005];
bool flag[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,map<int,int> > f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
		f[a[i]][++cnt[a[i]]]=i;
		gs[i]=tong[a[i]];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		for(int j=i;j<=n;j++){
			if(tong[a[j]]>1 && gs[j]+1<=cnt[a[j]]){
				j=f[a[j]][gs[j]+1]-1;
				continue;
			}
			flag[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(flag[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

