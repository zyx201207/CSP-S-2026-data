#include <bits/stdc++.h>
using namespace std;
long long m,n,c,d,q,w[100005],k[100005],a[10005][10005],t[10005][10005];
long long cnt=0,cen[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans=0;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]!=0){
				if(a[j][i]<cen[i]||cen[i]==0){
					cen[i]=t[j][i];
					cout << cen[i] << endl;
				}
			}
		}
	}
	while(q--){
		ans=0;
		int x,y;
		cin >> x >> y;
		for(int i=1;i<=n;i++){
			if(a[i][x]!=0&&a[i][y]!=0){
				cnt=t[i][x]+t[i][y];
			}
			else{
				for(int j=x;j<=y;j++){
					cnt+=cen[j];
					if(a[i][j]!=cen[j]){
					    cnt+=t[i][j];
					}
				}
			}
		}
		cnt+=w[x];
		cnt+=w[y];
		cout << cnt << "\n"; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
