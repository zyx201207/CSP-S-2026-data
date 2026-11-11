#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m,a[N],ans;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
