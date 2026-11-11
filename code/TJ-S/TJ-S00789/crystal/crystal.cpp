#include<bits/stdc++.h>
using namespace std;
long long a[500007],b[500007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout << "t           l    r            ll             ans\n";
	long long n,m;
	cin >> n >> m;
	a[0] = 0;
	b[0] = 0;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
//	for(int i = 1;i <= n;i++){
//		cout << a[i] << '\n';
//	}
	for(long long i = 1;i <= n;i++){
		b[i] = b[i-1]+a[i];
	}
	long long ans = 1;
	for(long long i = 2;i <= n;i++){//向a[i]靠拢 
		//cout << t << "         ";
		if(a[i]-a[i-1]>m){//如果连 上一个都不够 就不用算了 
			continue;
		}
		long long l = 1,r = i-1;
		//cout << l << "   " << r << "          ";
		while(l<r){//二分答案 
			long long mid = (l+r)/2;
			long long t = a[i]*(i-mid+1);//从mid到i应有的数值之和 
			long long z = b[i]-b[mid-1]; //从mid到i的和 
			if(t-z <= m){ //够 
				r = mid;
			}else{
				l = mid+1;//不够 
			}
		}
		//cout << l << "           ";
		ans = max(ans,i-l+1);//更新答案 
		//cout << ans << '\n';
	}
	cout << ans;
	return 0;
} 
