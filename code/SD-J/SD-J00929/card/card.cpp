#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],t[500005];
int h[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		b[i]=h[a[i]];
		h[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		memset(t,1,sizeof(t));
		int maxx=i;
		for(int j=n;j>=i;j--){
			if(t[j]==0){
				continue;
			}
			for(int k=j;k<=b[j];k++){
				t[k]=0;
			}
		}
		for(int j=n;j>=i;j--){
			if(t[j]!=0){
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
