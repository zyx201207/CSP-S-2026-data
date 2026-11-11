#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,c,t,e;
	int a[600000],b[400000],d[600000],ans[400000];
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	memset(b,0,sizeof(b));
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=n;i>=1;i--){
		e=a[i];
		if (b[e]==0){
			b[e]=i;
			c++;
		}
		else{
			if (c!=0){
				t=1;
				for (int j=i+1;j<=n;j++){
					if (d[j]!=0){
						j=d[j]-1;
						continue;
					}
					ans[a[j]]+=t;
					if (t<c){
						t++;
					}
				}
			}
			d[i] = b[e];
			b[e] = i;
			c=1;
		}
	}
	if (c!=0){
		t=1;
		for (int j=1;j<=n;j++){
			ans[a[j]]+=t;
			if (t<c){
				t++;
			}
			if (d[j]!=0){
				j=d[j];
			}
		}
		
	}
	for (int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
