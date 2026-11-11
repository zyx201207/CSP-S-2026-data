#include<bits/stdc++.h>
using namespace std;
int a[500005];
int num[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(num,0,sizeof(num));
		for(int j=i;j<=n;j++){
			if(num[a[j]]!=0){
				for(int k=num[a[j]];k<j;k++){
					num[a[k]]=0;
				}
			}
			num[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(num[j]!=0){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
