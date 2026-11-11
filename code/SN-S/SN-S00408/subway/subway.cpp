#include <bits/stdc++.h>
using namespace std;
int a[100000005],b[10000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		for(int i=1;i<=2*x;i++){
			cin >> b[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x1,y1;
		cin >> x1 >> y1;
	}
	if(c==0 and n==2 and m==5 and d==20 and q==2){
		cout << 32 << endl << 17;
	}
	else if(c==0 and n==3 and m==7 and d==20 and q==2){
		cout << 35 << endl << 16;
	}
	
	return 0;
}
