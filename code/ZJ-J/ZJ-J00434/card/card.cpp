#include<bits/stdc++.h>
using namespace std;
int ma[500086];
bool v[500086];
int a[500086];
int cnt[500086];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ma[a[j]]){
				for(int k=j-1;k>=i;k--){
					ma[a[k]]=0;
					if(a[k]==a[j])break;
				}
			}
			ma[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(ma[j])cnt[j]++;
			ma[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

