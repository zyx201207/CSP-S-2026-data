#include<bits/stdc++.h>
using namespace std;
long long a[1145140] = {}, b[1145140] = {}, c[1145140] = {};
long long m = 0, sum = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, cnt = 1, cntmax = 1;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++){
		b[i] = a[i] - a[i - 1];
	}
	c[1] = b[1];
	for(int i = 2; i < n; i++){
		c[i] = b[i] + c[i - 1];
	}
	int lari = 1;
	for(int i = 0; i < n; i++){//i表示第一指针，枚举数列的起点 
		for(int j = lari; j < n; j++){//j表示第二指针，枚举数列的终点 
			sum += b[j] * (j - i);
			if(sum > m){
				lari = j;
				sum = sum - c[j] + c[i] - b[j] * (j - i - 1);//
				cntmax = max(cnt, cntmax);
				cnt = j - i - 1;
				break;
			}else{
				cnt++;
				if(j == n - 1){
					cout << max(cnt, cntmax);
					return 0;
				}
			}
		}
	}
	cout << max(cnt, cntmax);
	return 0;
}
