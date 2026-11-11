//赵晗羽 西安辅轮中学  SN-J00667 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[100005],d[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int e=n,q=0;
	while(e--){
		int c[100005],p=0;
		for(int i=1;i<=n;i++)c[i]=0,b[i]=0;
		for(int i=++q;i<=n;i++){
			if(b[a[i]]==0){
				c[++p]=a[i];
				b[a[i]]=1;
			}else{
				int u=0;
				for(int j=1;j<=n;j++)if(c[j]==a[i])u=j;
				while(p>u){
					if(c[p]==0)continue;
					b[c[p]]=0;
					c[p--]=0;
				}
				p=u;
			}
		}
		for(int i=1;i<=p;i++)d[c[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
