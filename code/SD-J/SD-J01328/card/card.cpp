#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],fi[100010];
int mn[1000010];
int t[100010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int sx=0;
		for(int j=i; j<=n; j++) {
			sx++;
			if(fi[a[i]]!=0) {
				int fii=fi[a[i]];
				for(int k=fii+1;k<=sx; k++)mn[i]=0;
				sx=fii;
			} else {
				mn[sx]=a[i];
				fi[a[i]]=sx;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<mn[i]<<" ";
			t[i]+=mn[i];
			mn[i]=0;
			fi[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
