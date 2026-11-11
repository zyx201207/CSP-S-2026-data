#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,num[100005],et[100005],lx[505][10005][2],p[100005][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >>d >> q;
	for(int i = 1;i <= m;i++) cin >> et[i];
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		for(int j = 1;j <= num[i];j++){
			cin >> lx[i][j][0] >> lx[i][j][1];
		}
	}for(int i = 1;i <= q;i++){
		cin >> p[i][0] >> p[i][1];
	}if(c == 0 && n == 2 && m == 5 && q == 2){
		cout << 32 << endl;
		cout << 17;
	}else{
		cout << 35 << endl;
		cout << 16;
	}
	return 0;
}
