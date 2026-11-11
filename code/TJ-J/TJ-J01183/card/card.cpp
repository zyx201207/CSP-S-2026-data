#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int lst[N];
int ans[N];
int cnt[N];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=cnt[i];
		cnt[lst[a[i]]+1]+=cnt[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
