#include<bits/stdc++.h>
using namespace std;
#define long long 
const int N=5e5+10;
long long int n,m,a[N],b[N],t[N],ggg,cnt[N];
struct node{
	int wei,ys;
};
int main()
{
	freopen("card.in","r",stdin);
	freopen("caed.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n>>m;
	node ji[m];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(t[a[j]]!=1){
					b[x]=a[j];
					t[a[j]]++;
					ji[a[j]].ys++;
					ji[a[j]].wei=x;
					x++;
				}
				else if(t[a[j]]==1){
					t[a[j]]=0;
					for(int d=1;d<=m;d++){
						if(ji[d].ys==a[j]){
							ji[d].ys=0;
							for(int z=ji[d].wei;z<x;z++){
								b[z]=0;
							}
							t[a[j]]++;
						}
					}
				}
			}
			for(int j=1;j<=x;j++){
				cnt[b[j]]++;
			}
		}
	for(int i=1;i<=x;i++){
		if(cnt[i]!=0){
			cout<<i<<" ";
		}
	}
return 0;
}