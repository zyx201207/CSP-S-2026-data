#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int c;
int t;
int a[1000005];
bool cmp(int a , int b){
	return a < b;
}
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n;
		int d;
		cin>>n>>d;
		int as = 0;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		sort(a + 1 , a + 1 + n , cmp);
		for(int i = 1;i <= n;i++){
			for(int j = i + 3;j <= n;j++){
				int l = i;
				int r = j;
				while(l < r){
					int mid = (l + r) / 2;
					if(a[mid] >= a[i] + d){
						r = mid;
					}else{
						l = mid + 1;
					}
				}
				int r1 = l;
				l = i;
				r = j;
				while(l < r){
					int mid = (l + r) / 2;
					if(a[mid] >= a[j] - d){
						r = mid;
					}else{
						l = mid + 1;
					}
				}
				if(r1 - l + 1 == 2){
					as += 1;
				}
			}
		}
		cout<<as<<"\n";
	}
	return 0;
}
