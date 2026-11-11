#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005][31];
int tf[200005];
int f[31];
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=30;i++) f[i]=f[i-1]*2;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=30;j>=0;j--){
			if(x/f[j]>0){
				a[i][j]=1;
				x-=f[j];
			}
		}
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&tf[j]==0) cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=m;j++){
				if(a[j][i]==0) tf[j]=0;
			}
			sum+=f[i];
		}
	}
	cout<<sum;
	return 0;
}  