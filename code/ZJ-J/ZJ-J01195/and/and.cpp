#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans;
int a[200005][40];
int cnt[50];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	cnt[30]=n;
	for(int i = 0;i<n;i++){
		cin >> a[i][30];
	}
	for(int i = 29;i>=0;i--){
		int num=0;
		bool flag;
		for(int j = 0;j<cnt[i+1];j++){
			int t = (1<<i);
			if(a[j][i+1]&t){
				num++;
			}
		}
		ans<<=1;
		if(num>=m){
			flag = false;
			ans |= 1;
		}
		else{
			flag = true;
		}
		for(int j = 0;j<cnt[i+1];j++){
			int t = (1<<i);
			if((bool)(a[j][i+1]&t) || flag){
				a[cnt[i]++][i]=a[j][i+1];
			}
		}
	}
//	for(int i = 30;i>=0;i--){
//		for(int j = 0;j<cnt[i];j++){
//			clog << a[j][i] << " ";
//		}clog << endl;
//	}
	cout << ans;
	return 0;
}

