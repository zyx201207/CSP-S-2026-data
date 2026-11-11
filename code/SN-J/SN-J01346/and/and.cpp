#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int n,m,s,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++){
		int k=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			k%=a[j];
		}
		maxx=max(k,maxx);
	}
	cout<<maxx;
	return 0;
}

