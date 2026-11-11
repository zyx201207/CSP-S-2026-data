#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long a[N] = {},ans = 0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	
		cin>>c[i];
	}
	
	for(int i = 1, j = n;i < j;){
		if(a[i] >= a[j]){
			if(c[i] != c[j]){
				ans = ans + a[j];
				
			}
			
			a[i] -= a[j];
			j--;
		}else{
			if(c[i] != c[j]){
				ans = ans + a[i];
				
			}
			a[j] -= a[i];
			i++;
			
		}
		
	}
	printf("%lld\n",ans);
	return 0;
}
