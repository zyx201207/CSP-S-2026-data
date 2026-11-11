#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int la[500010],ans[500010];
int f[500010];//f[i]:a[i]之后第一个等于a[i]的数的下标，没有时f[i]=0 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(la[a[i]]!=0){
			f[la[a[i]]]=i;
		}
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int now=i;
		while(now<=n){
			if(f[now]!=0){
				now=f[now];
			}else{
				ans[a[now]]++;
				now++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
