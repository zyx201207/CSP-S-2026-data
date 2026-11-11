#include<bits/stdc++.h>
using namespace std;
int a[35],m,n;
long long num[200005],ans;//数
int bh[35][200005];//每位数码的编号 
int cnt[35];//每位数码个数
long long tot[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		long long x = num[i];
		for(int k = 0;k <= 30;k++){
			int mj = (x >> k) & 1;
			if(mj){
				bh[k][cnt[k]] = i;
				cnt[k]++;
			}
		}
	}
//	for(int i = 0;i <= 30;i++){
//		for(int j = 0;j < cnt[i];j++){
//			cout << num[bh[i][j]] << ' ';
//		}
//		cout << endl;
//	}
	for(int i = 30;i >= 0;i--){
//		cout << cnt[i] << ' ';
		if(cnt[i] == m){
			long long sc = num[bh[i][0]];
//			cout << sc << endl;
			for(int j = 0;j < cnt[i];j++){
				sc = (sc & num[bh[i][j]]);
			}
			cout << sc;
			return 0;
		}
	}
	return 0;
}