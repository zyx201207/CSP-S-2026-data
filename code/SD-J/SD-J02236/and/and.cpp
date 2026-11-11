#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],maxx=-2147483648;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(long long i=0; i<n; i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if(m==1) printf("%d",maxx);
	else{
		maxx=-2147483648;
		for(long long l=0; l<n; l++){
			for(long long r=0; r<n; r++){
				if(l==r) r++;
				if(r>=n) break;
				maxx=max(maxx,(a[l]&a[r]));
			}
		}
		printf("%d",maxx);
	}
	return 0;
}

