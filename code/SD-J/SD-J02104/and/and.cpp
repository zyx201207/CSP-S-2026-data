#include<bits/stdc++.h>
using namespace std;
const int N=222222;
int n,m,a[N],ans;
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp); 
	ans=a[m];
	cout<<ans;
	return 0;
}
