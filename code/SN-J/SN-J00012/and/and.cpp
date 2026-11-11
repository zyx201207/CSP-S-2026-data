#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2005],ans = 0;
//struct aaa{
//	long long a;
//	int b[25];
//	int x;
//}zj[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
//	int x = 0,sx;
	for (int i = 1;i<=n;i++){
		for (int j = i+1;j<=n;j++){
//			zj[x].a = a[i]&a[j];
//			zj[x].b[0] = i;zj[x].b[1] = j;zj[x].x = 1;
//			x++;
			if (a[i]&a[j]>ans) ans = a[i]&a[j]; 
		}
	}
//	sx = x;
//	m--;
//	while (m>1){
//		for (int i = 0;i<=sx;i++){
//			for (int j = 0;j<n;j++){
//				int canb = 0;
//				for (int t = 0;t<=zj[i].x;t++){
//					if (j == zj[i].b[t]) canb = 1;
//				}
//				if (canb) continue;
//				if (zj[i].a&a[j]>ans) ans = zj[i].a&a[j];
//			}
//		}
//	}
	cout<<ans;
	return 0;
} 
