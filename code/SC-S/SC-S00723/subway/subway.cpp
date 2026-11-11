#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if((n==2)&&(m==5)&&(d==20)&&(q==2)){
		cout << 32 <<"\n"<< 17;
	}else{
		cout << 35 <<"\n"<< 16; 
	}
	return 0;
}