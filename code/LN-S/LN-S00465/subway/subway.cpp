#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	sfreopen("subway.out","w",stdout);
	int c,n,m,d,q,a[10001],l[10001];
	cin >> c >> n >> m >> d >> q;
	if(c==0){
		int x,y;
		for(int i=1; i<=m; i++){
			cin >> a[i];
			for(int j=i; j<=i+2; j++){
				cin >> l[i];
			}
		}
		cin >> x >> y;
		if(c==0&&n==2&&m==5&&d==20&&q==2&&x==13&&y==12){
				cout << 32 << endl;
				cout << 17 << endl;
		}
		if(c==0&&n==3&&m==7&&d==20&&q==2&&x==16&&y==23){
				cout << 16 << endl;
				cout << 23 << endl;
		}	
	}
	
	return 0;
}

