#include <bits/stdc++.h>
using namespace std;

int n;
char h;
long long cnt = 0;
long long ccnt[500005];
char c[500005];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long cnt = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d %c",&ccnt[i],&c[i]);
	}
	
	for (int i = 1 ; i <= n/2; i++){
		if(c[i] != c[n-i+1]){
			cnt += ccnt[i];
		}
	}
	
	printf("%lld",cnt);
	
	return 0;
	
}
