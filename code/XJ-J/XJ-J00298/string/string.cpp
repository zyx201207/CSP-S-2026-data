#include <bits/stdc++.h>
using namespace std;
struct ll{
	long long s;
	string c;
};
int main(){
	freopen("string.in","w",stdin);
	freopen("string,out","r",stdout);
	int n,cnt=0;
	cin >> n;
	ll a[200000] ={};
	for (int i = 1;i<=n;i++){
		cin >>a[i].s>>a[i].c;
		cnt += a[i].s;
	}
	int mid,ans = 0;
	if (n%2==1){
		mid = cnt/2+1;
		for (int i = 1;i<=mid-1;i++)
			for (int j = mid+1;j<=n;j++){
				if (a[i].s!=a[j].s){
					a[j].s == a[i].s;
					ans++;
				}
			}
		}
		cout<<ans;
	if (n%2 == 0){
		mid = cnt/2;
		for (int i = 1;i<=mid;i++){
			for (int j = mid+1;j<=n;j++){
				if (a[i].s!=a[j].s){
					a[j].s = a[i].s;
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}