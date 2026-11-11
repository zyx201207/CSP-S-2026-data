#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100],x[100100],idx,cnt[100100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		idx=0;
		for(int j=i;j<=n;j++){
			for(int k=idx;k>=1;k--){
				if(x[k]==a[j]){
					for(int m=k;m<=idx;m++){x[m]=0;}
					idx=k-1;break;
				}
			}
			x[++idx]=a[j];
		}
		for(int j=1;j<=idx;j++){
			cnt[x[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

