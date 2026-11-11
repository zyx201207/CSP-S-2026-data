#include<algorithm>
#include<deque>
#include<iostream>
using namespace std;
int n , m , cnt , ans;
long long a[500001] , sum;
deque <int> dq;
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout); 
	scanf("%d%d" , &n , &m);
	for (int i = 1 ; i <= n ; i++)
		scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	for (int i = 1 ; i <= n ; i++){
		dq.push_back(a[i]);
		sum += a[i];
		while (dq.size() && a[i] * dq.size() - sum > m){
			sum -= dq.front();
			dq.pop_front();
		}
		ans = max(ans , int(dq.size()));
	}
	printf("%d" , ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
