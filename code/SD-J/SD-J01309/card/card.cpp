#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[500005],tot,st[500005],cnt[500005];
struct no{
	int wz,s;
}c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tot=0;
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(c[a[j]].s==0){
				c[a[j]].s=1;
				c[a[j]].wz=j;
				st[tot++]=a[j];
			}else{
				tot=c[a[j]].wz;
			}
		}
		for(int j=0;j<=tot-1;j++){
			cnt[st[j]]++;	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
