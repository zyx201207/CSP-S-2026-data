#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
struct node{
	int cnt,fst;
}tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			tong[a[j]].cnt++;
			if(tong[a[j]].cnt>1){
				for(int k=tong[a[j]].fst;k<j;k++)tong[a[k]].cnt=0;
				tong[a[j]].cnt=1;
				tong[a[j]].fst=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(tong[j].cnt!=0){
				ans[j]++;
				tong[j].cnt=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
