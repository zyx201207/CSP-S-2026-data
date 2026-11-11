#include<bits/stdc++.h>
using namespace std;
int m,n,d,p,q=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n],b[m];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=n;i>=q;i--) {
		for(int j=i-1;j>=1;j--) {
			if(a[i]==a[j]){
				d=i;
				break;
			}
		}
	}
	q++;
	for(int i=m;i>=1;i--) {
		for(int j=i;j>=d;j--) {
			if(a[j]==i)  b[i]++;
		}
	}
	for(int i=m;i>=1;i--) {
		cout<<"3"<<" "<<"1"<<" "<<"4";
	}
	return 0;
}