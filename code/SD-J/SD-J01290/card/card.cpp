#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],last[300005],cnt[300005];
vector<int> ans[500005]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans[n]={a[n]};
	last[a[n]]=1;
	cnt[a[n]]=n;
	for(int i=n-1,j=2;i>0;i--,j++){
		ans[i]=ans[i+1];
		if(a[j])
			for(int k=0;k<j-a[j];k++){
				cnt[ans[i][ans[i].size()-1]]--;
				ans[i].pop_back();
			}
		else cnt[a[j]]=i;
		ans[i].push_back(a[j]);
		last[a[j]]=j;
	}
	for(int i=0;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

