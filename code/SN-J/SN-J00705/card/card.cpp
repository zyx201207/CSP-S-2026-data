//heyuanwei xiantieyizhongxue SN-J00705 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],c[maxn],d[maxn],sum[maxn];
ll ans,x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++)c[i]=0;
		x=0;
		for(int j=1;j<=m;j++)d[i]=0;
		for(int j=i;j<=n;j++){
			if(!d[a[j]])d[a[j]]=++x,c[x]=a[j];
			else{
				int p=d[a[j]];
				for(int k=p;k<=x;k++){
					c[i]=0;
					for(int o=1;o<=m;o++)if(d[o]==k)d[o]=0;
				}
				x=p,d[a[j]]=x,c[x]=a[j];
			}
		}
		for(int j=1;j<=m;j++)if(d[a[j]]){
			sum[j]++;
			break;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
