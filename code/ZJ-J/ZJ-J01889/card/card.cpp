#include<bits/stdc++.h>
using namespace std;
int q[100010],b[100010],tt=0,cards[100010],n,m,ans[100010];
void work(int st){
	memset(q,0,sizeof q);
	memset(b,0,sizeof b);
	tt=0;
	for(int i=st;i<=n;i++){
		if(b[cards[i]]==0){
			q[++tt]=cards[i];
			b[cards[i]]=tt;
		}
		else {
			tt=b[cards[i]]+1;
			for(int j=b[cards[i]];j<=i;j++)b[q[j]]=0;
			b[cards[i]]=tt-1;
		}
	}
	for(int i=1;i<=m;i++)if(b[i])ans[i]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>cards[i];
	for(int i=1;i<=n;i++)work(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
