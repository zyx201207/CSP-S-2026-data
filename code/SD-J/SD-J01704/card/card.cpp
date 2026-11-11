#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],st[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		int p=n,q=i;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				if(j-1>=q) q=j-1;
				if(st[a[j]]<=p) p=st[a[j]];
				for(int o=p;o<=q;o++) b[a[o]]=0;
			}
			b[a[j]]=1;
			st[a[j]]=j;
			cout<<p<<' '<<q<<endl;
		}
		if(q>p){
			for(int j=1;j<=p;j++)c[a[j]]++;
			for(int j=q+1;j<=n;j++) c[a[j]]++;
		}else for(int j=i;j<=n;j++) c[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
