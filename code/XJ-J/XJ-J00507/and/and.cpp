#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+3;
int a[MAXN],n,ans=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}      
	sort(a+1,a+1+n);
	printf("%d",a[3]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}               
