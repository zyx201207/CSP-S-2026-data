#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[i];
	int count = 0;
	int c,n,m,d,g;
	cin >> c >> n >> m >> d >> g;
	for (int i = 1;i <= m;i ++){
		cin >> a[i];
	}
	int kone;
	cin >> kone;
	for (int i = 1;i <= 2 * kone;i ++){
		cin >> kfirst[i];
	}
	int ktwo;
	cin >> ktwo;
	for (int i = 1;i <= 2 * ktwo;i ++){
		cin >> kscond[i];
	}
	int x,y;
	for (int i = 1;i <= 2;i ++){
		cin >> x >> y;
	}
	for (int i = 1;i <= n;i ++){
		while (count){
			if(n + d >= count && y - x > 0){
				count += a[i];
				
			}
			else {
				count = a[i];
			}
		}
		for (int j = 1;j <= max(kone,ktwo);j ++){
			count += max(kfirst[i] - 1,ksecond[i] + kone[i-1]);
			if (count >= k[one]){
				continue;
			} 
		}
	}
	cout << count;
	return 0;
}

