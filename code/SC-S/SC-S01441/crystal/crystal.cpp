#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	int ans = -1;
	long long sum = 0;
	for(int i = 1,j = 1;j <= n;j++){
		sum+=a[j];
		while(a[j]*(j-i+1)-sum > m){
			i++;sum-=a[i];
		}
		ans = max(j-i+1,ans);
	}
	cout << ans;
	return 0;
}