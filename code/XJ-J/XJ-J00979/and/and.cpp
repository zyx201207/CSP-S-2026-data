#include <bits/stdc++.h>
using namespace std;
//ios::sync_with_stdio(false);
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i],cmp);
	}
	std::sort(a+1,a+n+1,cmp);
	int max=a[1];
	for(int i=1;i<=m;i++){
		std::sort(a+1,a+n+1,cmp);
		max=max&a[1];
		a[1]=0;
		for(int j=i;j<=n;j++){
			a[j]&=max;
		}
	}
	cout<<max;
	return 0;
}