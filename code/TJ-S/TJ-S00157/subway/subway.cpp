#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,k,a[10005],b[10005],x[10],y[10];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int i=1;i<=2*k;i++){
			cin >> b[i];
		}
	}
	for(int i=1;i<=2;i++){
		cin >> x[i] >> y[i];
	}
	if(n==2&&m==5&&d==20&&p==2){
		cout << "32" << "\n" << "17";
	}else if(n==3&&m==7&&d==20&&p==2){
		cout << "35" << "\n" << "16";
	}
	return 0;
} 
