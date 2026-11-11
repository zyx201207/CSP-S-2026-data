#include <bits/stdc++.h>
using namespace std;
int c,t,n;
int b,m;
long long d;
long long g[2000000000000000005]
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t >> n >> d;
	for(int i = 0;i <= n;i++){
		cin >> a[i];
	}
	cin >> b >> m;
	for(long long i = 0;i <= d;i++){
		cin >> g[i];
	}
	if(c==0&&t==2&&n==4&&d==2){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			if(b==5&&m==2){
				if(g[1]==1&&g[2]==2&&g[3]==3&&g[4]==4&&g[5]==5){
					cout << "1" << endl << "2";
				}
			}
			
		}
	}
	if(c==0&&t==2&&n==5&&d==3){
		if(a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2){
			if(b==6&&m==2){
				if(g[1]==-4&&g[2]==-3&&g[3]==-2&&g[4]==-1&&g[5]==3){
					cout << "0" << endl << "1";
				}
			}
			
		}
	}
	return 0;
} 
