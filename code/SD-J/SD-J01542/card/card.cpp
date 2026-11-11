#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],c[N],vis[N],cc[N],vis1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=i;
			}
			else{
				for(int p=vis[a[j]];p<j;p++){
					c[p]=1;
					vis[a[j]]=j;
				}
			}
		}
		for(int b=i;b<=n;b++){
			if(c[b]==0){
				cc[a[b]]++;
			}
		}
		for(int k=1;k<=n;k++){
			c[k]=0;
			vis[k]=0;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<cc[i]<<" ";
	}
	return 0;
}
