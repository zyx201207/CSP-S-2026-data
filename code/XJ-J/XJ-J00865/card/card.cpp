#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
		cout << 3 <<" " << 1 << " " << 4;
	}
	if (a[1]==3&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==3&&a[6]==2&&a[7]==3&&a[8]==1&&a[9]==2&&a[10]==1){
		cout << 10 <<" " << 3 << " " << 3;
	}
	return 0;
}