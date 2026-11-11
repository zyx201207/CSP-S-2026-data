#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,a[200005],cnt;
char c[200005];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int id = 1;//不同项数 
	for(int i = 1;i <= n;i++){
		cin >> a[id] >> c[id];
		if(c[id] == c[id-1]){
			a[id-1] += a[id];
			id--;
		}
		id++;
	}
	//思路：每次比较如果双方配置不同砍掉更少数目的一方，结果加上少的数目，然后车轮战直到俩指针会面 
	int left = 1,right = id-1;
	while(left < right){
		if(a[left] != a[right] or c[left] != c[right]){
			int minx = min(a[left],a[right]);
			if(a[left] == a[right]){//数目一样，直接两边砍掉 
				cnt += a[left];
				left++;
				right--;
				continue;
			}
			if(c[left] == c[right]){//如果字符一样就删最小项 
				if(a[left] == minx){
					a[right] -= a[left];
					left++;
				}
				else{
					a[left] -= a[right];
					right--;//注意right用-- 
				}
				continue;
			}
			else{
				if(a[left] == minx){//不同时加上不同的项数 
					a[right] -= a[left];
					cnt += a[left];
					left++;
				}
				else{
					a[left] -= a[right];
					cnt += a[right];
					right--;
				}
			}
		}
		else{
			left++;
			right--;
		}
	}
	cout << cnt;
	return 0;
}
