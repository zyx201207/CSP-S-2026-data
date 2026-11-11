#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	printf("%d",a[m]);
	return 0;
}
