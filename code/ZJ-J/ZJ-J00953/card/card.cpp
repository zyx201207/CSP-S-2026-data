#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[500010],t,f[500010],b[500010],ans[500010],g,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	if(n<=5000&&m<=3000){
		for (g=1;g<=n;g++){
			t=0;memset(f,0,sizeof(f));
			for (i=g;i<=n;i++)
				if(!f[a[i]]||f[a[i]]>t) b[++t]=a[i],f[a[i]]=t;
				else t=f[a[i]];
			for (i=1;i<=t;i++) ans[b[i]]++;
		}
		for (i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for (i=1;i<=n;i++)
		if(a[i]!=a[i+1]) cout<<i<<" ";
	return 0;
}
