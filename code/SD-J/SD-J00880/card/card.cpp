#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],idx[M],ans[M],ads,card[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ads=i;
		for(int j=i;j<=n;j++){
			if(!idx[a[j]])idx[a[j]]=ads,card[ads]=a[j],ads++;
			else{
				for(int k=idx[a[j]]+1;k<=ads;k++){
					idx[card[k]]=0;
					card[k]=0;
				}
				ads=idx[a[j]],ads++;
			}
		}
		for(int j=1;j<=m;j++){
			if(idx[j])ans[j]++,idx[j]=0;
		}
		for(int j=i;j<=n;j++)card[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
