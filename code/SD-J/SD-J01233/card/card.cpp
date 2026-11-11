#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=3e5+50;
int a[N],n,m,ls[M],res[M];
bool bo[N],boo[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		fill(bo+i,bo+n+1,0);
		fill(boo+1,boo+m+1,0);
		fill(ls+1,ls+m+1,5e5+20);
		for(int j=i;j<=n;j++){
			if(bo[ls[a[j]]]==0){
				for(int k=ls[a[j]];k<j;k++){
					bo[k]=1;
				}
			}
			ls[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(bo[j]==0) boo[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(boo[j]==1) res[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<res[i]<<" ";
	return 0;
}
