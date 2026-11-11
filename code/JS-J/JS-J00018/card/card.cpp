#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,flag=1;
	cin>>n>>m;
	vector<int>a(n+1,0),ans(m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])flag=0;
	}
	if(m==1){
		cout<<n;
	}
	else if(flag){
		vector<int>cnt(m+1,0);
		for(int i=1;i<=n;i++){
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans[i]=ans[i-1]+cnt[i];
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	else{
		for(int i=1;i<=n;i++){
			vector<int>x(m+1,0),id(m+1,0);
			for(int j=i;j<=n;j++){
				if(x[a[j]]==0){
					x[a[j]]++;
					id[a[j]]=j;
				}
				else{
					for(int k=id[a[j]];k<j;k++)x[a[k]]=0;
					x[a[j]]++;
					id[a[j]]=j;
				}
			}
			for(int j=1;j<=m;j++){
				if(x[j])ans[j]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
	return 0;
}
