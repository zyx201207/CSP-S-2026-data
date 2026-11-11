#include<bits/stdc++.h>
using namespace std;
long long m,a[300005],vis[300005],n,mk[300005],st[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int top=0;
		memset(mk,0,sizeof(mk));
		memset(st,0,sizeof(st));
		for(int j=i;j<=n;j++){
			st[++top]=a[j];
			
			if(mk[a[j]]){
				top--;
				while(st[top]!=a[j]){
					top--;
				}
				mk[a[j]]=j;
			}
			if(mk[a[j]]==0){
				mk[a[j]]=j;
			}
		}
		for(int j=1;j<=top;j++){
			vis[st[j]]++;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<vis[i]<<' ';
}
