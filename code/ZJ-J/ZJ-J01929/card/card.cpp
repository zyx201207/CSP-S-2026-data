#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[500005],f[500005],s[300005],p[5005][3005];bool l,b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]<a[i-1]) l=1;
	}if (l==0){
		for (int i=1;i<=m;i++){
			k=upper_bound(a+1,a+n+1,i)-a;
			cout<<k-1<<" ";
		}return 0;
	}for (int i=1;i<=n;i++){
		memset(f,0,sizeof(f));k=0;
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			if (b[a[j]]==1){
				while (f[k]!=a[j]){
					b[f[k]]=0;
					k--;
				}
			}else{
				b[a[j]]=1;
				f[++k]=a[j];
			}
		}for (int j=1;j<=k;j++) s[f[j]]++;
	}for (int i=1;i<=m;i++) cout<<s[i]<<" ";
}
