#include<bits/stdc++.h>
using namespace std;
const int N=5e3+3,M=3e3+3,MAXN=2e5+5,MAXM=1e5+5,MAX=5e5+5;
int n,m,f[N][M],f2[MAXN][3],lst[MAXM],a[MAX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5e3&&m<=3e3){
		for(int i=n;i>=1;i--){
			if(lst[a[i]])
				for(int j=1;j<=m;j++) f[i][j]=f[lst[a[i]]][j];
			else {
				for(int j=1;j<=m;j++) f[i][j]=f[i+1][j];
				f[i][a[i]]++;
			}
			lst[a[i]]=i;
		}
		for(int i=1;i<=m;i++) {
			int sum=0;
			for(int j=1;j<=n;j++) sum+=f[j][i];
			cout<<sum<<" ";
		}
		return 0;
	}
	else if(m<=2){
		for(int i=n;i>=1;i--){
			if(lst[a[i]])
				for(int j=1;j<=m;j++) f2[i][j]=f2[lst[a[i]]][j];
			else {
				for(int j=1;j<=m;j++) f2[i][j]=f2[i+1][j];
				f2[i][a[i]]++;
			}
			lst[a[i]]=i;
		}
		for(int i=1;i<=m;i++) {
			int sum=0;
			for(int j=1;j<=n;j++) sum+=f2[j][i];
			cout<<sum<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++) lst[a[i]]=i;
	for(int i=1;i<=m;i++) cout<<lst[i]<<" ";
	return 0;
} 
