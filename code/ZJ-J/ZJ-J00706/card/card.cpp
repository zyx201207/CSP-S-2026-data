#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int a[n+2]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans[m+2]={0};
	for(int i=1;i<=n;i++){
		int bucket[m+2]={0};
		for(int j=i;j<=n;j++){
			if(bucket[a[j]]!=0)for(int k=bucket[a[j]];k<j;k++)bucket[a[k]]=0;
			bucket[a[j]]=j;
		}
		for(int j=1;j<=m;j++)if(bucket[j]!=0)ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}