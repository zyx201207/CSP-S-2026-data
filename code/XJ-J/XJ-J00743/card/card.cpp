#include<bits/stdc++.h>
using namespace std;
int a[500005],flag[500005],num[500005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n; i++){
		memset(flag,0,sizeof(flag));
		for (int j = i;j <= n; j++){
			if (flag[a[j]] != 0){
				for (int k = flag[a[j]];k < j;k++){
					flag[a[k]] = 0;
				}
			}
			flag[a[j]] = j;
		}
		for (int j = 1;j <= m; j++){
			if (flag[j] != 0){
				num[j]++;
				flag[j] = 0;
			}
		}
		cout << endl;
	}
	for (int i = 1;i <= m; i++){
		cout << num[i] << " ";
	}
} 
