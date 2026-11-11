#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500010],b[500010];
int h;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]+=10;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		b[i]=b[i-1]+a[i];
	}
	for(int i=1,j=1;j<=n;i++) {
		while((a[j+1]*(j+1-i+1)-(b[j+1]-b[i-1]))<=m&&j+1<=n) {
			j++;
		}
		if(i>j) break;
		h=max(h,j-i+1);
//		cout<<i<<' '<<j<<'\n';
	}
	cout<<h;
} 





//
//1 3 7 8
//  2 6 7
//    4 5
//      1
//
//1 5 


//4 8 9
//
//4 12 21
//
//5 1
//6
//
//21-8
//1 2
//4 8 9  21
//9+9+9-9-8-4



