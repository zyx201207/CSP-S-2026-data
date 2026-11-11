#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int t[500005]={},p[300005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		memset(p,0,sizeof(p));
		for(int i=l;i<=n;i++){
			t[i]=a[i];
		}
		for(int i=l;i<=n;i++){
			if(p[t[i]]!=0&&t[p[t[i]]]!=0){
				for(int j=p[t[i]];j<=i-1;j++){
					t[j]=0;
				}
			}
			p[t[i]]=i;
		}
		for(int i=l;i<=n;i++){
			ans[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

