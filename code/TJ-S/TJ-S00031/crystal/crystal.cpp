#include <cstdio>
#include <algorithm>
using namespace std;
int n,c = 1,t;
long long m,a[500001],s[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		s[i] = a[i] + s[i - 1];
	}
	for(int l = 0,r = 2;r <= n;r++){
		t = r - l;
		while(a[r] * t - s[r] + s[l] > m && t > 1){
			l++;
			t--;
		}
		if(t > c) c = t;
	}
	printf("%d",c);
	return 0;
}
