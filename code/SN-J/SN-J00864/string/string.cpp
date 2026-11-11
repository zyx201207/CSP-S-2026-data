#include <iostream>
using namespace std;
int cnt,n;
long long sum[200005],a[200005];
char s[200005];
bool check(int x,int y){
	char j,h;
	bool flag1 = false,flag2 = false;
	for (int i = 1; i <= n; i++){
		if (sum[i] >= x && !flag1){
			j = s[i];
			flag1 = true;
		}
		if (sum[i] >= y && !flag2){
			h = s[i];
			flag2 = true;
		}
		if (flag1 && flag2){
			break;
		}
	}
	return (j == h);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int l,r;
	if (sum[n] % 2 == 1){
		l = (sum[n] + 1) / 2;
		r = (sum[n] + 1) / 2;
	}
	else{
		l = sum[n] / 2;
		r = sum[n] / 2 + 1;
	}
	while (r <= sum[n]){
		if (!check(l,r)){
			cnt++;
		}
		l--;
		r++;
	}
	cout << cnt << endl;
	return 0;
}
