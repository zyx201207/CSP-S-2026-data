#include <bits/stdc++.h>
using namespace std;
const int N=5e5+67;
int n,k=1,a[N],b[N],dp[N],s=0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%ull",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1) b[i]=0;
		else b[i]=a[i]-a[i-1];
		s+=b[i];
	}
	for(int i=n;i>=2;i--){
		int x=0,j=i;
		while(x<m && j!=1){
			x+=b[j];
			j--;
		}
		k=max(k,i-j);
	}
	printf("%d",k+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
