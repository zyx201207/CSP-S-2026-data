//chenjingxuan xianshidibashijiuzhongxue SN-J00683
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[m+5];
	for(int i = 1;i<=n;i++)
	cin >> a[i];
	sort(a,a+n+1);
	int sum = 0;
	for(int i = 1;i<=m;i++){
		sum = a[n-i+1]&a[n-i];
	}
	cout << sum;
	return 0;
}
