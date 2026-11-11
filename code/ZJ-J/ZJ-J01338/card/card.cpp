#include<bits/stdc++.h>
using namespace std;
int x,y;
int a[500001];
int ans[300001],flag[300001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++) cin>>a[i];
	for(int i=1;i<=x;i++){
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=x;j++){
			if(flag[a[j]]==0) flag[a[j]]=j;
			else if(flag[a[j]]!=0){
				for(int k=flag[a[j]];k<=j-1;k++){
					flag[a[k]]=0;
				} 
				flag[a[j]]=j;
			}
		}
		for(int j=1;j<=y;j++){
			if(flag[j]!=0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=y;i++) cout<<ans[i]<<' ';
	return 0;
}