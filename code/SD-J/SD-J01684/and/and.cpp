#include <bits/stdc++.h>
using namespace std;
const int INT=2e5;
int n,m,l,maxx;
int a[INT];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==n){
		maxx = a[1];
		for(int i=2;i<=n;i++){
			maxx = maxx&a[i]; 
		}
		printf("%d",maxx);
		return 0;
	}
	sort(a+1,a+n+1);
	l = 1;
	while(l<=n){
		for(int i=l+1;i<=n;i++){
			if((a[l]&a[i])>maxx){
				maxx = (a[l]&a[i]);
			}
		}
		l++;
	}
	printf("%d",maxx);
	return 0;
}
