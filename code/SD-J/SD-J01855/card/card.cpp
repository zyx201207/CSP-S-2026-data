#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(int k=j-1;k>=t[a[j]];k--){
					t[a[j]]=0;
				}
			}
			t[a[j]]=j;
		}
		//cout<<t[2];
		for(int i=1;i<=m;i++){
			if(t[i]>0){
				cnt[i]++;
				t[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
