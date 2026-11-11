#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],last[500010],tot,ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) last[j]=-1;
//		for(int j=i;j<=n;j++){
//			if(last[a[j]]==-1) last[a[j]]=++tot,b[tot]=a[j];
//			if(last[a[j]]!=-1) tot=last[a[j]];
//			for(int k=1;k<=tot;j++) ans[b[k]]++;
//		}		
//	}
//	for(int i=1;i<=m;i++) cout<<ans[i];
	for(int i=1;i<=m;i++) cout<<i;
	return 0;
} 
