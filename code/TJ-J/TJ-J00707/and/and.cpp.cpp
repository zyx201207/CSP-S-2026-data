#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
long long oo=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++) {
    	cin>>a[i];		 
	}
	if(m==n){
		for(int i=0;i<=n;i++) {
    		oo=a[i]&oo;
		}
	}
	if(m==1){
		oo=0;
		for(int i=0;i<=n;i++) {
    		if(oo<=a[i]) {
    			oo=a[i];
			}
		}
	}
	cout<<oo;
	return 0;
} 
