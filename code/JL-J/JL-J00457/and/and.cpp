#include<bits/stdc++.h>
using namespace std;
int n,m,a[200200],b[200200];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(b[i]>a[j]){
				b[i]=a[j];
			}
		}
		for(int j=0;j<n;++j){
			if(b[i]==a[j]){
				a[j]=-10;
			}
		}
	}
	cout<<b[m-1];
	return 0;
}
