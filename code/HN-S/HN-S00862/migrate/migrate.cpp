#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[600001];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int klbq =0; klbq<t; klbq++) {
		int n,d;
		cin>>n>>d;
		for(int i= 0; i<n; i++) {
			cin>>a[i];
		}
		int sum = 0;
		for(int i =0; i<n; i++) {
			int num = a[i]+d+d;
			for(int j = i+3; j<n; j++) {
				if(a[j]!=a[i]+d) {
					if(a[j]<=num) {
						sum+=1;
						i+=3;
					}
				}
			}
		}
		cout<<sum;
	}
}
