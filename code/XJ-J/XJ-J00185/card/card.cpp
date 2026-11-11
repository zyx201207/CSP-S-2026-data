#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int ans[M],cnt[M];
struct node{
	int lst,idx;
}kk[M];
bool cmp(node p,node q){
	return p.lst<q.lst; 
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		kk[a[i]].lst=i;
		kk[a[i]].idx=a[i];
		ans[a[i]]=cnt[a[i]];
	}
	sort(kk+1,kk+m+1,cmp);
	for(int i=1;i<=m;i++){
		ans[a[kk[i].lst+1]]+=ans[kk[i].idx];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
