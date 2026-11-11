#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[101010];
int x[101010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d %lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	
	int mx = -1,num = 0,n2;
	for(int i = 2;i <= n;i++){
		n2 = n;
		for(int j = 1;j <= i;j++){
			if(a[i]>=a[j]){
				x[j] = a[i] - a[j];
			}
			num += x[j];
		}
		sort(x+1,x+n+1);
		if(num > m&&n2<=i){
			for(int j = n;j>=1;j--){
				num-=x[j];
				x[j] = 0;
				n2--;
				if(num<=m)break;
			}
		}
		if(n2>mx&&n2>=i)mx = n2;
	}
	printf("%d",mx);
	return 0;
}
