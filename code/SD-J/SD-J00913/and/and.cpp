#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int m,n;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int ans1=a[1],ans2=a[m];
	for(int i=2,j-m-1;i<=m;i++,j--){
		ans1&=a[i];
		ans2&=a[j];
	}
	cout<<max(ans1,ans2);
	return 0;
}
