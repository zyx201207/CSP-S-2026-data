#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int arr[N];
struct node{
	int num,p;
};
node cnt[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	} 
	for(int k=1;k<=n;k++){
		for(int cc=1;cc<=m;cc++){
			cnt[cc].num=0;
			cnt[cc] .p=0;
		}
	for(int i=k;i<=n;i++){
		int t=arr[i];
		if(cnt[t].num!=0){
			for(int j=cnt[t].p;j<=i-1;j++){
				cnt[arr[j]].num=0;
			}
			cnt[t].num=1;
			cnt[t].p=i;
		}
		else{
			cnt[t].num=1;
			cnt[t].p=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i].num!=0) ans[i]++;
	}
}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	} 
	return 0;
} 
