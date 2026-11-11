#include<cstdio>
#include<iostream>
using namespace std;
const int M=5e5+5;
int n,m,a[M],lst[M],cnt[M],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cnt[i]++;
		ans[a[i]]+=cnt[i];
		cnt[lst[a[i]]+1]+=cnt[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
