#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=m;k++){
				for(int l=1;l+m<=n;l++)
					if((a[i] & a[k+l])>ma)
						ma=(a[i] & a[k+l]);
			}
		}
	}cout<<ma;
	return 0;
}
