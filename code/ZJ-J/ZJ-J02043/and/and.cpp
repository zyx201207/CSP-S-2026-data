#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[n+10][m+10],ans=-1;
	cin >> n >> m;
	memset(a,-1,sizeof(a));
	for (int i=1;i<=n;i++){
		cin >> a[i][1];
		for (int j=1;j<i;j++){
			for (int p=1;p<m;p++){
				if (a[j][p]!=-1){
					long long k=a[j][p]&a[i][1];
					if (k>a[i][p+1]) a[i][p+1]=k;
				}
			}
		}
		if (a[i][m]>ans) ans=a[i][m];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
