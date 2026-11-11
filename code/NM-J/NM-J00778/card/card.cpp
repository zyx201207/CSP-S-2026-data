#include<bits/stdc++.h>
using namespace std;
int a[5005][5005],c[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int v=0,n,m,u=0,ans=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=c[u];
			u++;
			for(int k=0;k<u;k++){
				if(a[i][k]==a[i][j]){
					for(int f=k+1;f<=j;f++){
						a[i][f]=0;
					}
				}
			}
		}
		v++;
		u=v;
    }
    v=n;
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[j][k]==i){
					ans++;
				}
			}
		}
		cout << ans << " ";
		ans=0;
	}
	return 0;
}
