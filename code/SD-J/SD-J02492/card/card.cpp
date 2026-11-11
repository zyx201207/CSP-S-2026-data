#include<bits/stdc++.h>
using namespace std;
int const MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],b[MAXM],p[MAXN],k,ans[MAXM];
void f() {
	for(int i=1; i<=n; i++) {
		b[i]=0;
		p[i]=0;
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	bool w=1;
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		
		if(a[i]<a[i-1]) w=0;
		
	}
	
	if(w==1){
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	
	for(int i=1; i<=n; i++) {
		f();
		k=1;
		for(int x=i; x<=n; x++) {
			if(b[a[x]]>0) {
				for(int j=b[a[x]]+1; j<=k; j++) {
					b[p[j]]=0;
					p[j]=0;
				}
				k=b[a[x]]+1;
			} else {
				b[a[x]]=k;
				p[k]=a[x];
				k++;
			}
		}
		for(int j=1; j<k; j++) {
			ans[p[j]]+=1;
		}
	}
	for(int j=1; j<=m; j++) {
		cout<<ans[j]<<" ";
	}
	return 0;
}
