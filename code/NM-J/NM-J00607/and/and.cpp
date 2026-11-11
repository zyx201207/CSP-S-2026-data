#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	long long a[200005]={},sum[400005]={};
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sum[0]=a[1];
	for(int i=m;i<n+m;i++){
		for(int j=m;j>0;j--){
			sum[i]=sum[i-j]&a[i-j];
		}
	}
	sort(sum+m,sum+(n+m),cmp);
	//for(int i=1;i<n+m;i++){
	//	cout << sum[i] << " ";
	//}
	cout << sum[m];
	return 0;
}
