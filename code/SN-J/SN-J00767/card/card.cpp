//SN-J00767 汤佳忆 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
bool cmp;
int n,m,cnt[N],a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i-1]==a[i])cmp=1;
	}
	if(!cmp)for(int i=1;i<=m;++i)cout<<i<<" ";
	else{
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n+1;++j){
				if(a[j]!=a[j+1])cnt[a[j]]++;
			}
		}
		for(int i=1;i<=m;++i)cout<<cnt[i]<<" ";
	}
	return 0;
}
