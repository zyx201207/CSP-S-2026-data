#include <bits/stdc++.h>
using namespace std;

int c[30]={0};
struct A {
	int s;
	int jz;
};

bool cmp (A z,A y) {
	return z.s>y.s;
}

int main() {
	freopen("card.in","r",stdin);
 	freopen("card.out","r",stdin);
	
	int n;
	int m;
	cin>>n>>m;
	
	int a[500000]={0};
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	
	for (int i=0; i<n; i++) {
		int ans=0;
		int a2[500000]={0};
		int x=0;
		for (int j=i; j<n; j++) {
			a2[x]=a[j];
			for (int k=0; k<x; k++) {
				if (a2[x-1]==a[k]) {
					for (int l=a[k]; l<a2[x]; i++) {
						a2[i]=0;
					}
					x=k;
					break;
				}
			}
			x++;
		}
		for (int j=0; j<x; j++) {
			if (a2[j]==j) {
				ans++;
			}
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
