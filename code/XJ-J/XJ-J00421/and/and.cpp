#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j>=2;j--){
			int h;
			if(a[j]>a[j-1]){
				h=a[j-1];
				a[j-1]=a[j];
				a[j]=h;
			}
		}
	}
	cout<<a[m];
	return 0;
}
