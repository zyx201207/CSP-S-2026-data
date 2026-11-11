#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500){
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof(c));
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++){
				c[j]=1;
				b[a[j]]++;
				if(b[a[j]]>1){
					long long k=j-1;
					while(k>=i){
						if(a[k]==a[j]&&c[k]==1) break;
						k--;
					}
					for(int x=k;x<j;x++){
						if(c[x]!=0)b[a[x]]--;
						c[x]=0;
					}
				}
			}
			for(int j=1;j<=m;j++){
				if(b[j]>0) ans[j]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	}
	else if(m<=2){
		if(m==1) cout<<n;
		else{
			ans[a[n]]=n;
			for(int i=n-1;i>=1;i--){
				if(a[i]!=a[n]) ans[a[i]]++;
			}
			for(int i=1;i<=m;i++){
				cout<<ans[i]<<' ';
			}	
		}
	}
	else{
		for(int i=1;i<=n;i++) ans[a[i]]=i;
		for(int j=1;j<=m;j++) cout<<ans[j]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/