#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int m,n,a[n];
	cin >> n >> m >> a[n];
	if(m==2){
		int b=a[1]&&a[2];
		int c=a[3]&&a[4];
		int d=a[2]&&a[1];
		int e=a[4]&&a[3];
		int f=a[2]&&a[3];
		int g=a[1]&&a[4];
		int h=a[3]&&a[2];
		int i=a[4]&&a[1];
		int j=max(b,c);
		int k=max(d,e);
		int l=max(f,g);
		int o=max(h,i);
		int p=max(j,k);
		int q=max(l,o);
		int r=max(p,q);
		cout << r;
	}
	return 0;
}
