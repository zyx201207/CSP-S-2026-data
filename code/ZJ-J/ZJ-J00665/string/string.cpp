#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;

long long n , a[N] , ji[N];
char c[N];
long long sum , ans;

int main(){
	
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(long long i = 1 ; i <= n ; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
		ji[i] = a[i];
	}
	long long mid = (sum + 1) / 2;
	long long index = 0;
	for(long long i = 1 , j = n ; i <= n , j >= 1 ; ){
		bool flag1 = false , flag2 = false;
		if(index + ji[i] >= mid){
			flag1 = true;
			long long tmp = (index + ji[i] - mid);
			if(tmp <= ji[i] / 2){
				a[i] -= 2 * tmp;
				if(sum % 2 == 1)
					a[i]--;
				flag2 = true;
			}
			else{
				a[i] -= 2 * (mid - index + 1);
				if(sum % 2 == 1)
					a[i]--;
			}
		}
		if(flag1){
			if(!flag2)
				break;
			else{
				long long xiao = a[i];
				if(c[i] != c[j])
					ans += a[i];
				break;
			}
		}
		
		long long wu = min(a[i] , a[j]);
		a[i] -= wu , a[j] -= wu;
		if(c[i] != c[j])
			ans += wu;
		if(a[i] == 0){
			index += ji[i];
			i++;
		}
		if(a[j] == 0)
			j--;
	}
	
	cout << ans << endl;
	
	return 0;
}
