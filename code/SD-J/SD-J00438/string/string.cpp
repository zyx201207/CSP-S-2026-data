#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5+10;

int n;
int a[maxn];
char c[maxn];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
//		ans += a[i]%2;//jiouxing
	}
//	for(int i = 1;i <= n;i++){
//		printf("%d %c\n",a[i],c[i]);
//	}
//	cout << a
	int ans = 0;
	int l = 1, r = n;
	while(l != r){
		if(l > r)break;
		if(c[l] == c[r]){
//			printf("zifu相同\n");
			if(a[l] == a[r]){
//				printf("shu liang xiang tong1\n");
				l++;r--;
//				if(l == r-1 && n % 2 == 0){
//					break;
//				}
//				printf("")
//				continue;
			}else if(a[l] < a[r]){
//				printf("zuo geng xiao1\n");
				a[r]-=a[l];
				l++;
			}else{
//				printf("you geng xiao1\n");
				a[l] -=a[r];
				r--;
			}
		}else{
//			printf("zifu不同\n");
			if(a[l] == a[r]){
//				printf("shu liang xiang tong2\n");
				ans += a[l];
				l++;r--;
			}else if(a[l] < a[r]){
//				printf("zuo geng xiao2\n");
//				printf("jia shang%d",a[l]);
				ans += a[l];
				a[r] -= a[l];
				l++;
			}else if (a[l] > a[r]){
//				printf("you geng xiao2\n");
//				printf("jia shang%d\n",a[r]);
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
		}
	}
	cout << ans;
//	for(int i = 1;i <= n/2;i++){
//		if(c[i] == c[n-i+1]){
//			int s = min(a[i],a[n-i+1]);
//			a[i]-=s;
//			a[n-i+1]-=s;
//			if(a[i] == a[n-i+1]){
//				continue;
//			}else if(a[i] == 0){
//				while()
//			}else{
//				
//			}
//		}
//		
//	}
	return 0;
}
