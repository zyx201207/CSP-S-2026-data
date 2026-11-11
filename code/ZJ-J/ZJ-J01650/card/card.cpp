#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cur[N],ans[N];
struct node{
	bool f;
	int weizhi;
}st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(st,0,sizeof st);
		memset(cur,0,sizeof cur);
		for(int j=i;j<=n;j++){
			if(st[a[j]].f){
				for(int k=st[a[j]].weizhi;k<j;k++)cur[k]=0,st[a[k]].f=0;
				st[a[j]].f=1,st[a[j]].weizhi=j,cur[j]=a[j];
			}
			else st[a[j]].f=1,st[a[j]].weizhi=j,cur[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(cur[j])ans[cur[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
