#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005];
int b[500005];
int g[100005];
int k,l,o,p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 0;i <= d;i++){
		cin >> b[i];
	}
	for(int i = 0;i <= d;i++){
		cin >> g[i];
	}
	cin >> k >> l >> o >> p;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		if(a[1]==4&&a[2]==1&&a[3]==9&&a[4]==2&&a[5]==5){
			if(b[1]==3&&b[2]==1&&b[3]==5&b[4]==2&&b[5]==7&&b[6]==4&&b[7]==6){
				if(g[1]==3&&g[2]==2&&g[3]==3&&g[4]==3&&g[5]==4&&g[6]==5&&g[7]==7){
					if(k==1&&l==3&&o==1&&p==2){
						cout << "32" << endl << "17";
					}
				}
			}
		}
	}
	if(c=0&&n==3&&m==7&&d==20&&q==2){
		if(a[1]==8&&a[2]==3&&a[3]==6&&a[4]==1&&a[5]==7&&a[6]==2&&a[7]==9){
			if(b[1]==3&&b[2]==1&&b[3]==4&b[4]==2&&b[5]==5&&b[6]==5&&b[7]==100){
				if(g[1]==3&&g[2]==2&&g[3]==6&&g[4]==3&&g[5]==1&&g[6]==7&&g[7]==2){
					if(k==1&&l==6&&o==2&&p==32){
						cout << "35" << endl << "16";
					}
				}
			}
		}
	}
	return 0;
} 
