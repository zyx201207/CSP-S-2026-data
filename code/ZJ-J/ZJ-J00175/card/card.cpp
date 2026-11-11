#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],ans[300005];
int v[500005],res;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				for(int k=cnt[a[j]]+1;k<res;k++)cnt[v[k]]=0;
				res=cnt[a[j]];
			}
			else cnt[a[j]]=res,v[res++]=a[j];
		}
		for(int i=0;i<res;i++)ans[v[i]]++,cnt[v[i]]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}