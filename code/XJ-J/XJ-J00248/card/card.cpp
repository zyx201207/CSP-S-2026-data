#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long a[N],cnt[M],cnta[N],p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long x=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cnta[a[j]]++;
			p[x]=a[j];
			x++;
			for(int k=x-1;k>=0;k--){
				if(cnta[p[k]]==2){
					for(int l=k-1;l>=0;l--){
						if(p[l]!=a[j]){
							cnta[p[l]]--;
							x--;
						}
						else{
							cnta[p[l]]--;
							x--;
							break;
						}
					}
					break;
				}	
			}
		}
		for(int j=0;j<x;j++){
			cnt[p[j]]++;
		}
		memset(p,0,sizeof(p));
		memset(cnta,0,sizeof(cnta));
		x=0;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

