#include<bits/stdc++.h>
using namespace std;
int m,n,a[500001],b[300001],ans[300001],l[300001];
int nxt[500001],pre[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pre[a[i]])nxt[pre[a[i]]]=pre[a[i]]=i;
		else pre[a[i]]=i;
	}for(int i=1;i<=n;i++){
		memset(l,0,sizeof l);
		for(int j=i;j<=n;j=(nxt[j]?nxt[j]:j+1))
			if(!l[a[j]]){
				ans[a[j]]++;
				l[a[j]]=1;
			}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
