#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005];
int f[500005];
int x[500005];
int r;
int sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	r=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		r=0;
		memset(a,0,500005);
		for(int z=i;z<=n;z++){
			if(a[x[z]]==1){
				while(f[r]!=x[z]){
					a[f[r]]=0;
					r--;
				}
			}else{
				a[x[z]]=1;
				f[++r]=x[z];
			}
		}
		for(int j=1;j<=r;j++){
			sum[f[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
}