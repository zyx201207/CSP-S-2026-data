#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ti=2;
	int h[111111];
	int a[111111][111111],aaa[111111];
	cin >> c >> n;
	cin >> m >> d >> q;
	for (int i=0;i<m;i++) cin >> h[i];
	int k[n];
	for (int i=0;i<n;i++){
		cin >> k[i];
		for (int j=0;j<k[i];j++){
			cin >> a[i][j] >> aaa[j];
		}
	}
	for (int i=0;i<q;i++){
		int st,fi;
		cin >> st >> fi;
		int aa=0,aaaa=0;
		for (int j=0;j<n;j++){
			if (a[j][0]==st){
				aa=j;
				break;
			} 
		}
		for (int j=0;j<n;j++){
			if (a[j][0]==fi){
				aaaa=j;
				break;
			} 
		}
		if (aa!=aaaa) ti+=2; 
		cout << ti*aaa[0] << endl;
		ti=2;
	}
	return 0;
} 
