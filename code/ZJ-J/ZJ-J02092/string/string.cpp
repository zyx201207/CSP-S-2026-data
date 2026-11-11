#include<bits/stdc++.h>
#define N 200005
typedef long long ll;
using namespace std;
int n;
int a[N];
char c[N];
ll L,cnt,ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	L = 0;
	cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d %c",&a[i],&c[i]);
		L += a[i];
	}
	int i = 1,j = n;
	while(cnt < ((L + 1) >> 1)){
		if(a[i] > a[j]){
			a[i] -= a[j];
			if(c[i] != c[j]) ans += a[j];
			cnt += a[j];
			j--;
		}else if(a[i] < a[j]){
			a[j] -= a[i];
			if(c[i] != c[j]) ans += a[i];
			cnt += a[i];
			i++;
		}else{
			if(c[i] != c[j]) ans += a[i];
			cnt += a[i];
			i++,j--;
		}
	}
	printf("%lld",ans);

	return 0;
}
