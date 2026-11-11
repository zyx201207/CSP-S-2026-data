#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,num;
	cin>>n>>num;
	long long m[n];
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	int a=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int o=m[j];
			for(int q=1;q<num;q++){
				if(n-j>=q){
					o=o&m[q+j];
					a=max(o,a);
				}
			}
		}
	}
	cout<<a;
	return 0;
}
