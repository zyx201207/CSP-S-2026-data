#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),ans(m+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<int>f(m+1,0);
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				for(int k=j-1;k>=i;k--){
					f[a[k]]=0;
					if(a[k]==a[j])break;
				}
			}
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++)if(f[j])ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
