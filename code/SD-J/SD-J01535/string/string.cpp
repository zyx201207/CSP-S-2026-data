#include <bits/stdc++.h>
using namespace std;
int n,x = 1,y = 1;
long long s;
int ax[200005],ay[200005];
char cx[200005],cy[200005];
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> ax[i] >> cx[i];
		ay[n - i + 1] = ax[i];
		cy[n - i + 1] = cx[i];
	}
	while (x <= n && y <= n){
		if (ax[x] == ay[y] && cx[x] == cy[y]){
			x++;
			y++;
			continue;
		}
		if (ax[x] == ay[y] && cx[x] != cy[y]){
			s += ax[x];
			x++;
			y++;
			continue;
		}
		if (ax[x] != ay[y] && cx[x] == cy[y]){
			if (ax[x] > ay[y]){
				ax[x] -= ay[y];
				y++;
				continue;
			}
			if (ax[x] < ay[y]){
				ay[y] -= ax[x];
				x++;
				continue;
			}
		}
		if (ax[x] != ay[y] && cx[x] != cy[y]){
			if (ax[x] > ay[y]){
				s += ay[y];
				ax[x] -= ay[y];
				y++;
				continue;
			}
			if (ax[x] < ay[y]){
				s += ax[x];
				ay[y] -= ax[x];
				x++;
				continue;
			}
		}
	}
	cout << s / 2;
	return 0;
}
