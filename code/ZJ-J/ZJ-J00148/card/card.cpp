#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
int b[N],pre[N],last[N],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=m+5;
	for(int i=1;i<=n+1;i++)
		if(a[i]!=a[i-1] && i!=1)
			b[++cnt]=a[i-1];
	for(int i=1;i<=cnt;i++) last[i]=-1;
	for(int i=1;i<=cnt;i++){
		last[pre[b[i]]]=i;
		pre[b[i]]=i;
	}
	int l=0,s=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) l++;
		for(int j=l;j<=cnt;j++){
			if(last[j]!=-1) j=last[j]-1;
			else ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<" ";
	}
	cout<<'\n';
	return 0;
}
