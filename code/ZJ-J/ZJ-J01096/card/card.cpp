#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[1000001],f[1000001],z[1000001],l,j,k,o[1000001],ans;
struct no{
	int t,w;
}b[1000001];
bool cmp(no q,no h){
	return q.w<h.w;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]) ans++;
	}
	if(ans==n){
		for(i=1;i<=n;i++)
			f[a[i]]=i;
		for(i=1;i<=m;i++)
			cout<<f[i]<<" ";
		return 0;		
	}
	for(i=1;i<=n;i++){
		if(f[a[i]]!=0){
			b[++l].t=f[a[i]];
			b[l].w=i;
		}
		f[a[i]]=i;
	}
	sort(b+1,b+1+l,cmp);
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++) f[j]=0;
		for(j=1;j<=m;j++) o[j]=0;
		for(j=1;j<=l;j++){
			if(b[j].t>=i)
				if(f[b[j].t]==0&&f[b[j].w]==0)
					for(k=b[j].t;k<b[j].w;k++) f[k]=1;
		}
		for(j=i;j<=n;j++)
			if(f[j]==0&&o[a[j]]==0) z[a[j]]++,f[j]=1,o[a[j]]=1;
	}
	for(i=1;i<=m;i++)
		cout<<z[i]<<" ";
	return 0;	
}

